#include "./move.h"
#include "../../dual_stack/dual_stack.h"

void perform_move(t_dual_stack *state, int index) {
    t_stack *a = state->a;
    
    int distance_to_top = index;
    if (index > a->size / 2) {
        distance_to_top = a->size - index;
    }
    
    for (int i = 0; i < distance_to_top; i++) {
        if (index > a->size / 2) {
            reverse_rotate_a(state);
        } else {
            rotate_a(state);
        }
    }
    push_b(state);
}

int find_max_in_b(t_stack *b, int *index) {
    t_node *current = b->top;
    int max_val = b->top->data;
	int current_index = 0;

    while (current) {
        if (current->data > max_val) {
            max_val = current->data;
			*index = current_index;
        }
		current_index ++;
        current = current->next;
    }
    return max_val;
}
/*
void rotate_b_for_insert(t_dual_stack *state, int value) {
    t_stack *b = state->b;
    if (!b || b->size <= 1)
        return;

    t_node *current = b->top;
    int best_index = 0;

	int max_val_index = 0;

    // Si el valor es mayor que todos los valores en B, lo insertamos al inicio
    if (value > find_max_in_b(b, &max_val_index)) {
        best_index = max_val_index;
    }
    else {
        // Buscar el lugar adecuado en B donde insertar el valor
        while (current && current->next) {
            if (value > current->data && value < current->next->data) {
                break;
            }
            current = current->next;
            best_index++;
        }

        // Si el valor es menor que todos los valores de B, insertarlo al final
        if (!current) {
            best_index = b->size;
        }
    }

    // Rotar B según el índice calculado
    if (best_index <= b->size / 2) {
        // Rotaciones hacia arriba (rb)
        for (int i = 0; i < best_index; i++) {
            rotate_b(state);
        }
    } else {
        // Rotaciones hacia abajo (rrb)
        for (int i = 0; i < b->size - best_index; i++) {
            reverse_rotate_b(state);
        }
    }
}*/

void rotate_b_for_insert(t_dual_stack *state, int value) {
	t_stack *b = state->b;
	if (!b || b->size <= 1)
		return;

	t_node *current = b->top;
	//int index = 0;
	int best_index = 0;

	// Caso por defecto: insertar después del valor máximo (el mayor reinicio en orden)
	t_node *max_node = b->top;
	int max_index = 0;

	for (int i = 0; current && current->next; i++, current = current->next) {
		if (current->data > max_node->data) {
			max_node = current;
			max_index = i;
		}
		if (value < current->data && value > current->next->data) {
			best_index = i + 1;
			break;
		}
	}

	// Si no encontramos hueco, colocamos después del mayor
	if (best_index == 0 && !(value < b->bottom->data && value > b->top->data))
		best_index = max_index;

	if (best_index >= b->size)
		best_index = 0;

	// Rotamos hacia arriba o abajo según convenga
	if (best_index <= b->size / 2) {
		for (int i = 0; i < best_index; i++)
			rotate_b(state);
	} else {
		for (int i = 0; i < b->size - best_index; i++)
			reverse_rotate_b(state);
	}
}



void move(t_dual_stack *dual, int index_in_a)
{
	rotate_b_for_insert(dual, get_value_at_index(dual->a, index_in_a));
	perform_move(dual, index_in_a);
}