#include "./gready_but_smart.h"
#include "./cost/cost.h"
#include "./move/move.h"
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
	int n_candidates = 3;
	int a_size = state->a->size;
	t_dual_stack **candidates = malloc(n_candidates * sizeof(t_dual_stack *));

	int *scores = malloc(a_size * sizeof(int));
	int i = 0;
	while (i < a_size)
	{
		scores[i] = calculate_cost_for_index_in_a(state, i);
		i++;
	}
	int lowest_scores_index[n_candidates];
	indices_menores(scores, a_size, n_candidates, lowest_scores_index);
	i = 0;
	while (i < n_candidates)
	{
		candidates[i] = duplicate_dual_stack(state);
		move(candidates[i], lowest_scores_index[i]);
		printf("%d\n", scores[lowest_scores_index[i]]);
		i++;
	}
	return (candidates);
}