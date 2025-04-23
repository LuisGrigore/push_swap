#include "./move.h"
#include "../../dual_stack/dual_stack.h"
#include <stdio.h>

void put_index_on_top_a(t_dual_stack *state, int index)
{
	if (index <= (state->a->size/2)-1)
	{
		while (index > 0)
		{
			rotate_a(state);
			index --;
		}
		return;
	}
	index = state->a->size - index;
	while (index > 0)
	{
		reverse_rotate_a(state);
		index --;
	}
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

int find_min_in_b(t_stack *b, int *index) {
    t_node *current = b->top;
    int min_val = b->top->data;
	int current_index = 0;

    while (current) {
        if (current->data < min_val) {
            min_val = current->data;
			*index = current_index;
        }
		current_index ++;
        current = current->next;
    }
    return min_val;
}

void put_index_on_top_b(t_dual_stack *state, int index)
{
	if (index <= state->b->size/2)
	{
		while (index > 0)
		{
			rotate_b(state);
			index --;
		}
		return;
	}
	index = state->b->size - index;
	while (index > 0)
	{
		reverse_rotate_b(state);
		index --;
	}
}

int find_best_index(t_dual_stack *state, int value)
{
	int max_index = 0;
	int max_val = find_max_in_b(state->b, &max_index);
	
	int min_index = 0;
	int min_val = find_min_in_b(state->b, &min_index);

	if (value > max_val || value < min_val)
		return max_index;

	int min_greater_than_value = min_val;
	int current_index = 0;
	int target_index = 0;
	t_node *current = state->b->top;
	while (current)
	{
		if (current->data < value && current->data >= min_greater_than_value)
		{
			min_greater_than_value = current->data;
			target_index = current_index;
		}
		current_index ++;
		current = current->next;
	}
	return target_index;
}


void rotate_b_for_insert(t_dual_stack *state, int value)
{
	put_index_on_top_b(state, find_best_index(state, value));
}

void move(t_dual_stack *dual, int index_in_a)
{
	rotate_b_for_insert(dual, get_value_at_index(dual->a, index_in_a));
	put_index_on_top_a(dual, index_in_a);
	push_b(dual);
}