/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:08:30 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 20:56:29 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_cheapest.h"
#include "node_data.h"
#include "target.h"
#include "util.h"
#include <limits.h>

static void	rotate_a_to_target(t_double_stack *stack,
		t_current_cheapest cheapest)
{
	t_dll_node	*current;
	t_node_data	*data_a;
	int			target_pos;

	target_pos = get_target(stack, cheapest.cheapest_index);
	current = stack->a->head;
	data_a = (t_node_data *)current->data;
	while (data_a->position != target_pos)
	{
		current = current->next;
		data_a = (t_node_data *)current->data;
	}
	while (((t_node_data *)stack->a->head->data)->index != data_a->index)
	{
		if (cheapest.costs.cost_a > 0)
			do_ra(stack);
		else
			do_rra(stack);
	}
}

static void	rotate_b_to_target(t_double_stack *stack,
		t_current_cheapest cheapest)
{
	while (((t_node_data *)stack->b->head->data)->index
		!= cheapest.cheapest_index)
	{
		if (cheapest.costs.cost_b > 0)
			do_rb(stack);
		else
			do_rrb(stack);
	}
}

static void	move_cheapest(t_double_stack *stack, t_current_cheapest cheapest)
{
	rotate_b_to_target(stack, cheapest);
	rotate_a_to_target(stack, cheapest);
	do_pa(stack);
}

void	do_cheapest(t_double_stack *stack)
{
	t_dll_node			*current;
	t_node_data			*data_b;
	t_cost				costs;
	t_current_cheapest	current_cheapest;
	int					lowest_cost;

	current_cheapest.cheapest_index = -1;
	current = stack->b->head;
	lowest_cost = INT_MAX;
	while (current)
	{
		data_b = (t_node_data *)current->data;
		costs = get_costs(stack, data_b->position, data_b->index);
		if (abs(costs.cost_a) + abs(costs.cost_b) < lowest_cost)
		{
			lowest_cost = abs(costs.cost_a) + abs(costs.cost_b);
			current_cheapest.costs.cost_a = costs.cost_a;
			current_cheapest.costs.cost_b = costs.cost_b;
			current_cheapest.cheapest_index = data_b->index;
		}
		current = current->next;
	}
	if (current_cheapest.cheapest_index == -1)
		return ;
	move_cheapest(stack, current_cheapest);
}
