/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:02:54 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/01 16:20:13 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "sort.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

static void	tiny_sort(t_stack **stack)
{
	int	highest;

	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

static void	assign_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

static void	big_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;

    while ((*stack_a)->next && (*stack_a)->next->next->next)
        do_pb(stack_a, &stack_b);
	
	tiny_sort(stack_a);
	//free_stack(stack_b);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->index == 0 && ptr->value > value)
			{
				value = ptr->value;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

void	sort(t_stack **stack, int size)
{
	if(is_sorted(*stack))
		return;
	if (size == 2)
	{
		do_sa(stack);
		return ;
	}
	assign_index(*stack, size);
	if (size == 3)
		tiny_sort(stack);
	else
		big_sort(stack);
}
