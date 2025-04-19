#include "./a_star.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// ----------------------------
// Nodo para A*
// ----------------------------
typedef struct s_node {
    t_dual_stack* ds;
    int g;
    int h;
    struct s_node* next;
} t_node_a;

// ----------------------------
// Funciones de utilidad
// ----------------------------
t_stack* clone_stack(t_stack* original) {
    t_stack* copy = malloc(sizeof(t_stack));
    copy->size = original->size;
    copy->top = NULL;

    t_node* curr = original->top;
    while (curr) {
        t_node* new_node = malloc(sizeof(t_node));
        new_node->data = curr->data;
        new_node->next = copy->top;
        copy->top = new_node;
        curr = curr->next;
    }
    return copy;
}

t_op_stack* clone_op_stack(t_op_stack* src) {
    int len = 0;
    while (src && src[len]) len++;
    t_op_stack* copy = malloc(sizeof(char*) * (len + 1));
    for (int i = 0; i < len; i++)
        copy[i] = strdup(src[i]);
    copy[len] = NULL;
    return copy;
}

t_dual_stack* clone_dual_stack(t_dual_stack* ds) {
    t_dual_stack* new_ds = malloc(sizeof(t_dual_stack));
    new_ds->a = clone_stack(ds->a);
    new_ds->b = clone_stack(ds->b);
    new_ds->op_stack = clone_op_stack(ds->op_stack);
    return new_ds;
}

int is_sorted(t_stack* s) {
    t_node* curr = s->top;
    while (curr && curr->next) {
        if (curr->data > curr->next->data)
            return 0;
        curr = curr->next;
    }
    return 1;
}

// Mejoramos la heurística, ahora evaluamos la longitud de la subsecuencia creciente más larga
int longest_increasing_subsequence(t_stack* s) {
    int max_len = 0;
    int current_len = 1;
    t_node* curr = s->top;
    
    while (curr && curr->next) {
        if (curr->data < curr->next->data) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 1;
        }
        curr = curr->next;
    }

    return current_len > max_len ? current_len : max_len;
}

int heuristic(t_dual_stack *ds) {
    int count = 0;
    
    // Subsequencia creciente más larga en stack_a
    int lis_a = longest_increasing_subsequence(ds->a);
    count += (ds->a->size - lis_a) * 2;  // Penaliza más si la subsecuencia creciente es corta

    // Penalización por la cantidad de elementos en b
    count += ds->b->size * 2;

    if (ds->b->size > 0)
        count += ds->b->size * 3;

    return count;
}
/*
void apply_op_by_index(t_dual_stack* ds, int index) {
    switch (index) {
        case 0: swap_a(ds); break;
        case 1: swap_b(ds); break;
        case 2: swap_a_swap_b(ds); break;
        case 3: push_a(ds); break;
        case 4: push_b(ds); break;
        case 5: rotate_a(ds); break;
        case 6: rotate_b(ds); break;
        case 7: rotate_a_rotate_b(ds); break;
        case 8: reverse_rotate_a(ds); break;
        case 9: reverse_rotate_b(ds); break;
        case 10: reverse_rotate_a_reverse_rotate_b(ds); break;
    }
}*/

void apply_op_by_index(t_dual_stack* ds, int index) {
    switch (index) {
        case 0: swap_a(ds); break;
        case 1: swap_b(ds); break;
        case 2: push_a(ds); break;
        case 3: push_b(ds); break;
        case 4: rotate_a(ds); break;
        case 5: rotate_b(ds); break;
        case 6: reverse_rotate_a(ds); break;
        case 7: reverse_rotate_b(ds); break;
    }
}


void insert_sorted(t_node_a** head, t_node_a* new_node) {
    if (!*head || (new_node->g + new_node->h) < ((*head)->g + (*head)->h)) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    t_node_a* cur = *head;
    while (cur->next && (cur->next->g + cur->next->h) <= (new_node->g + new_node->h))
        cur = cur->next;
    new_node->next = cur->next;
    cur->next = new_node;
}
char* state_key(t_dual_stack* ds) {
    char* key = malloc(1024);
    char buf[12];
    key[0] = '\0';

    t_node* curr = ds->a->top;
    while (curr) {
        sprintf(buf, "%d,", curr->data);
        strcat(key, buf);
        curr = curr->next;
    }

    strcat(key, "|");
    curr = ds->b->top;
    while (curr) {
        sprintf(buf, "%d,", curr->data);
        strcat(key, buf);
        curr = curr->next;
    }

    return key;
}
// ----------------------------
// A* Algoritmo con poda
// ----------------------------
void a_star_push_swap(t_dual_stack* start) {
    t_node_a* open = NULL;
    t_node_a* initial = malloc(sizeof(t_node_a));
    initial->ds = start;
    initial->g = 0;
    initial->h = heuristic(start);
    initial->next = NULL;
    insert_sorted(&open, initial);

    char** visited = NULL;
    int visited_count = 0;

    while (open) {
        t_node_a* cur = open;
        open = open->next;

        // Verifica si el stack está ordenado
        if (is_sorted(cur->ds->a) && cur->ds->b->size == 0) {
            printf("Stack A final (ordered):\n");
            start->a = cur->ds->a;
			start->op_stack = cur->ds->op_stack;  // Asigna el stack ordenado al original
            return;
        }

        char* key = state_key(cur->ds);
        bool skip = false;

        // Poda por estado duplicado usando un conjunto de claves
        for (int i = 0; i < visited_count; i++) {
            if (strcmp(visited[i], key) == 0) {
                skip = true;
                break;
            }
        }

        if (skip) {
            free(key);  // Liberar memoria del estado duplicado
            continue;
        }

        visited = realloc(visited, sizeof(char*) * (visited_count + 1));
        visited[visited_count++] = key;

        // Aplica las operaciones y muestra el estado de la pila
        for (int i = 0; i < 8; i++) {
            t_dual_stack* new_ds = clone_dual_stack(cur->ds);
            apply_op_by_index(new_ds, i);

            t_node_a* new_node = malloc(sizeof(t_node_a));
            new_node->ds = new_ds;
            new_node->g = cur->g + 1;
            new_node->h = heuristic(new_ds);
            new_node->next = NULL;
            insert_sorted(&open, new_node);
        }
    }
}
