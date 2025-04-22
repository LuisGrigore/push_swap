#include "./cost.h"
#include <stdlib.h>

int calculate_move_cost(t_dual_stack *state, int index) {
    t_stack *a = state->a;
    int cost = 0;
    int distance_to_top = index;
    if (index > a->size / 2) {
        distance_to_top = a->size - index;
    }
    cost += distance_to_top;
    cost += 1;
    return cost;
}

int calculate_b_rotation_cost(t_dual_stack *dual, int value)
{
	t_stack *b = dual->b;
	if (!b || b->size == 0)
		return 0;

	if ((value > b->top->data && value < b->bottom->data) ||
		(value > b->top->data && b->top->data > b->bottom->data) ||
		(value < b->bottom->data && b->top->data > b->bottom->data)) {
		return 0;
	}

	t_node *current = b->top;
	int index = 0;
	int best_index = 0;

	while (current && current->next) {
		if (value < current->data && value > current->next->data) {
			best_index = index + 1;
			break;
		}
		current = current->next;
		index++;
	}

	if (index == b->size - 1) {
		current = b->top;
		t_node *max_node = b->top;
		int max_index = 0;
		int i = 0;

		while (current) {
			if (current->data > max_node->data) {
				max_node = current;
				max_index = i;
			}
			current = current->next;
			i++;
		}
		best_index = max_index;
		if (best_index == b->size)
			best_index = 0;
	}

	if (best_index <= b->size / 2)
		return best_index;
	else
		return b->size - best_index;
}

int calculate_cost_for_index_in_a(t_dual_stack *dual, int index_in_a)
{
	return(calculate_move_cost(dual, index_in_a) + calculate_b_rotation_cost(dual, get_value_at_index(dual->a, index_in_a)));
}