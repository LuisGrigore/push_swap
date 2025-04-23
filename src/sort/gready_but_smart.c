#include "./gready_but_smart.h"
#include "./cost/cost.h"
#include "./move/move.h"
#include "../utils/bool.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void init_gready_but_smart(t_gready_but_smart *gready_but_smart_state, t_dual_stack *initial_state)
{
	gready_but_smart_state->initial_state = initial_state;
	gready_but_smart_state->current_state = initial_state;
	gready_but_smart_state->result = NULL;
	gready_but_smart_state->current_depth = 0;
	gready_but_smart_state->n_elements = initial_state->a->size;
}


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

void print(t_dual_stack *new_result)
{
	t_node *current = new_result->b->top;
	printf("\n");
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
}

void set_result(t_dual_stack **result, t_dual_stack *new_result)
{

	destroy_dual_stack(*result);
	*result = duplicate_dual_stack(new_result);
	//print(new_result);
}

void gready_but_smart_aux(t_dual_stack *current_state, t_dual_stack **result, int current_depth, t_bool result_init)
{
	t_dual_stack *current_result = *result;
	if(current_depth == DEPTH)
	{
		if(current_state->total_ops < current_result->total_ops)
			set_result(result, current_state);
		return;
	}

	t_dual_stack **candidates = get_candidates(current_state);
	if (!result_init)
	{
		set_result(result, candidates[0]);
		result_init = TRUE;
	}
	int i = 0;
	while (i < N_CANDIDATES && (candidates[i]->a->size > 0))
	{
		gready_but_smart_aux(candidates[i], result, current_depth + 1, result_init);
		i++;
	}
}

void gready_but_smart(t_dual_stack **initial_state)
{
	t_dual_stack *result = NULL;
	push_b(*initial_state);
	while (!result || result->a->size > 0)
	{
		gready_but_smart_aux(*initial_state, &result, 0, FALSE);
		*initial_state = result;
	}
	
}

void test(t_dual_stack **initial_state)
{
	t_dual_stack *initial = *initial_state;
	push_b(initial);
	while (initial->a->size > 0)
	{
		initial = get_candidates(initial)[0];

	}
	*initial_state = initial;
}