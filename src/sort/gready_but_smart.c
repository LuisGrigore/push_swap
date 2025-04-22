#include "./gready_but_smart.h"
#include "./cost/cost.h"
#include "./move/move.h"
#include "../utils/bool.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>


void indices_menores(const int* arr, int size, int n, int* resultado) {
    if (n > size || n <= 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        int min_val = INT_MAX;
        int min_idx = -1;

        for (int j = 0; j < size; j++) {
            int usado = 0;
            for (int k = 0; k < i; k++) {
                if (resultado[k] == j) {
                    usado = 1;
                    break;
                }
            }

            if (!usado && arr[j] < min_val) {
                min_val = arr[j];
                min_idx = j;
            }
        }

        resultado[i] = min_idx;
    }
}


t_dual_stack **get_candidates(t_dual_stack *state)
{

	int a_size = state->a->size;
	t_dual_stack **candidates = malloc(N_CANDIDATES * sizeof(t_dual_stack *));

	int *scores = malloc(a_size * sizeof(int));
	int i = 0;
	while (i < a_size)
	{
		scores[i] = calculate_cost_for_index_in_a(state, i);
		i++;
	}
	int lowest_scores_index[N_CANDIDATES];
	indices_menores(scores, a_size, N_CANDIDATES, lowest_scores_index);
	i = 0;
	while (i < N_CANDIDATES)
	{
		candidates[i] = duplicate_dual_stack(state);
		move(candidates[i], lowest_scores_index[i]);
		printf("%d\n", scores[lowest_scores_index[i]]);
		i++;
	}
	free(scores);
	return (candidates);
}

t_bool b_success(t_stack *b) {
	t_node *top = b->top;

    while (top != NULL && top->next != NULL) {
        if (top->data < top->next->data) {
            return FALSE;
        }
        top = top->next;
    }
    return TRUE;
}

/*
void gready_but_smart(t_dual_stack *initial_state)
{

}*/