/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:08:30 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 19:14:07 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_cheapest.h"
#include "util.h"
#include "node_data.h"
#include <limits.h>

static int	get_cost_to_top(int pos, int size)
{
	if (pos > size / 2)
		return ((size - pos) * -1);
	return (pos);
}

static int	get_target(t_double_stack *stack, int b_idx)
{
	t_dll_node	*current_a;
	t_node_data	*data_a;
	int			target_idx;
	int			target_pos;

	current_a = stack->a->head;
	target_idx = INT_MAX;
	target_pos = 0;
	while (current_a)
	{
		data_a = (t_node_data *)current_a->data;
		if (data_a->index > b_idx && data_a->index < target_idx)
		{
			target_idx = data_a->index;
			target_pos = data_a->position;
		}
		current_a = current_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	current_a = stack->a->head;
	target_idx = INT_MAX;
	while (current_a)
	{
		data_a = (t_node_data *)current_a->data;
		if (data_a->index < target_idx)
		{
			target_idx = data_a->index;
			target_pos = data_a->position;
		}
		current_a = current_a->next;
	}
	return (target_pos);
}

static void	move_cheapest(t_double_stack *stack, t_current_cheapest cheapest)
{
	t_dll_node	*current;
	t_node_data	*data_a;
	int			target_pos;

	while (((t_node_data *)stack->b->head->data)->index
		!= cheapest.cheapest_index)
	{
		if (cheapest.costs.cost_b > 0)
			do_rb(stack);
		else
			do_rrb(stack);
	}
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
		costs.cost_b = get_cost_to_top(data_b->position, stack->b->size);
		costs.cost_a = get_cost_to_top(get_target(stack, data_b->index),
				stack->a->size);
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
