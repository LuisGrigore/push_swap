/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:02:54 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 15:34:12 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// static void	assign_position(t_stack_node **stack)
// {
// 	t_stack_node	*tmp;
// 	int				i;

// 	tmp = *stack;
// 	i = 0;
// 	while (tmp)
// 	{
// 		tmp->position = i;
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

// static int	get_target(t_stack_node **a, int b_idx, int target_idx,
// 		int target_pos)
// {
// 	t_stack_node	*tmp_a;

// 	tmp_a = *a;
// 	while (tmp_a)
// 	{
// 		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
// 		{
// 			target_idx = tmp_a->index;
// 			target_pos = tmp_a->position;
// 		}
// 		tmp_a = tmp_a->next;
// 	}
// 	if (target_idx != INT_MAX)
// 		return (target_pos);
// 	tmp_a = *a;
// 	while (tmp_a)
// 	{
// 		if (tmp_a->index < target_idx)
// 		{
// 			target_idx = tmp_a->index;
// 			target_pos = tmp_a->position;
// 		}
// 		tmp_a = tmp_a->next;
// 	}
// 	return (target_pos);
// }

// void	assign_target_positions_for_b(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*tmp_b;
// 	int				target_pos;

// 	tmp_b = *b;
// 	target_pos = 0;
// 	while (tmp_b)
// 	{
// 		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
// 		tmp_b->target = target_pos;
// 		tmp_b = tmp_b->next;
// 	}
// }

// static void	shift_stack(t_stack_node **stack_a)
// {
// 	int	lowest_pos;
// 	int	stack_size;

// 	stack_size = get_stack_size(*stack_a);
// 	lowest_pos = get_lowest_index_position(stack_a);
// 	if (lowest_pos > stack_size / 2)
// 	{
// 		while (lowest_pos < stack_size)
// 		{
// 			do_rra(stack_a);
// 			lowest_pos++;
// 		}
// 	}
// 	else
// 	{
// 		while (lowest_pos > 0)
// 		{
// 			do_ra(stack_a);
// 			lowest_pos--;
// 		}
// 	}
// }
// void	assign_costs(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	t_stack_node	*tmp_a;
// 	t_stack_node	*tmp_b;
// 	int				size_a;
// 	int				size_b;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	size_a = get_stack_size(tmp_a);
// 	size_b = get_stack_size(tmp_b);
// 	while (tmp_b)
// 	{
// 		tmp_b->cost_b = tmp_b->position;
// 		if (tmp_b->position > size_b / 2)
// 			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
// 		tmp_b->cost_a = tmp_b->target;
// 		if (tmp_b->target > size_a / 2)
// 			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
// 		tmp_b = tmp_b->next;
// 	}
// }
// void	do_cheapest_move(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	t_stack_node	*tmp;
// 	int				cheapest;
// 	int				cost_a;
// 	int				cost_b;

// 	tmp = *stack_b;
// 	cheapest = INT_MAX;
// 	while (tmp)
// 	{
// 		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
// 		{
// 			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
// 			cost_a = tmp->cost_a;
// 			cost_b = tmp->cost_b;
// 		}
// 		tmp = tmp->next;
// 	}
// 	do_move(stack_a, stack_b, cost_a, cost_b);
// }
// static void	big_sort(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	while ((*stack_a)->next && (*stack_a)->next->next->next)
// 		do_pb(stack_a, stack_b);
// 	tiny_sort(stack_a);
// 	while (*stack_b)
// 	{
// 		assign_position(stack_a);
// 		assign_position(stack_b);
// 		assign_target_positions_for_b(stack_a, stack_b);
// 		assign_costs(stack_a, stack_b);
// 		do_cheapest_move(stack_a, stack_b);
// 	}
// 	if (!is_list_sorted(*stack_a))
// 		shift_stack(stack_a);
// }

static void	tiny_sort(t_double_stack *stack)
{
	int	highest;

	highest = find_highest_index(stack->a);
	if (stack->a->head->index == highest)
		do_ra(stack);
	else if (stack->a->head->next->index == highest)
		do_rra(stack);
	if (stack->a->head->index > stack->a->head->next->index)
		do_sa(stack);
}

static void set_b(t_double_stack *stack)
{
	while(stack->a->size > 3)
	{
		do_pb(stack);
	}
}

static void get_cost_to_top(int pos, int size)
{
	if (pos > size/2)
		return ((size - pos) * -1);
	return(pos);
}

static void do_cheapest(t_double_stack *stack)
{
	
}

static void big_sort(t_double_stack *stack)
{
	set_b(stack);
	while(stack->b->size > 0)
	{
		do_cheapest(stack);
	}
	
}

void	sort(t_double_stack *stack)
{
	if (is_list_sorted(stack->a))
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
