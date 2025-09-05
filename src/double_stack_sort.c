/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:02:54 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 11:55:02 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "node_data.h"
#include "util.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


static int	find_highest_index(t_double_link_list *list)
{
	int			index;
	t_dll_node	*current;
	t_node_data	*current_data;

	current = list->head;
	index = 0;
	while (current)
	{
		current_data = (t_node_data *)current->data;
		if (current_data->index > index)
			index = current_data->index;
		current = current->next;
	}
	return (index);
}

static void	tiny_sort(t_double_stack *stack)
{
	t_node_data	*data_head;
	t_node_data	*data_second;
	int			highest;

	highest = find_highest_index(stack->a);
	data_head = (t_node_data *)stack->a->head->data;
	data_second = (t_node_data *)stack->a->head->next->data;
	if (data_head->index == highest)
		do_ra(stack);
	else if (data_second->index == highest)
		do_rra(stack);
	if (data_head->index > data_second->index)
		do_sa(stack);
}

static void	set_b(t_double_stack *stack)
{
	while (stack->a->size > 3)
	{
		do_pb(stack);
	}
}

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

	// Buscar el índice más pequeño mayor que b_idx
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

static void	do_cheapest(t_double_stack *stack)
{
	t_dll_node	*current;
	t_node_data	*data_b;
	t_node_data	*data_a;
	int			cost_a, cost_b;
	int			best_cost_a = 0, best_cost_b = 0;
	int			target_pos;
	int target_index;
	int			lowest_cost;
	int			cheapest_index = -1;

	current = stack->b->head;
	lowest_cost = INT_MAX;
	while (current)
	{
		data_b = (t_node_data *)current->data;
		cost_b = get_cost_to_top(data_b->position, stack->b->size);
		target_pos = get_target(stack, data_b->index);
		cost_a = get_cost_to_top(target_pos, stack->a->size);

		if (abs(cost_a) + abs(cost_b) < lowest_cost)
		{
			lowest_cost = abs(cost_a) + abs(cost_b);
			best_cost_a = cost_a;
			best_cost_b = cost_b;
			cheapest_index = data_b->index;
		}
		current = current->next;
	}

	if (cheapest_index == -1)
		return;

	// mover el nodo cheapest a la cabeza de B
	while (((t_node_data *)stack->b->head->data)->index != cheapest_index)
	{
		if (best_cost_b == 0)
			break;
		
		if (best_cost_b > 0)
			do_rb(stack);
		else
			do_rrb(stack);
	}

	// colocar el target en A en la posición correcta
	target_pos = get_target(stack, cheapest_index);
	current = stack->a->head;
	data_a = (t_node_data *) current->data;
	while(data_a->position != target_pos)
	{
		current = current->next;
		data_a = (t_node_data *) current->data;
	}
	while (((t_node_data *)stack->a->head->data)->index != data_a->index)
	{
		if (best_cost_a == 0)
			break;
		if (best_cost_a > 0)
			do_ra(stack);
		else
			do_rra(stack);
	}

	// finalmente pushear de B a A
	do_pa(stack);
}

static void	big_sort(t_double_stack *stack)
{
	t_dll_node *current;
	t_node_data *current_data;
	set_b(stack);
	tiny_sort(stack);
	while (stack->b->size > 0)
	{
		do_cheapest(stack);
	}
	current = stack->a->head;
	current_data = (t_node_data *) current->data;
	while(current_data->index != 0)
	{
		
		if (current_data->index < stack->a->size/2)
			do_rra(stack);
		else
			do_ra(stack);
		current_data = (t_node_data *) stack->a->head->data;
	}
}

static int	is_sorted(t_double_stack *stack)
{
	t_dll_node	*current;
	t_node_data	*current_data;
	t_node_data	*next_data;

	current = stack->a->head;
	while (current->next != NULL)
	{
		current_data = (t_node_data *)current->data;
		next_data = (t_node_data *)current->next->data;
		if (current_data->value > next_data->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort(t_double_stack *stack)
{
	if (is_sorted(stack))
		return ;
	if (stack->a->size == 2)
		do_sa(stack);
	else if (stack->a->size == 3)
		tiny_sort(stack);
	else
	{
		big_sort(stack);
	}
}
