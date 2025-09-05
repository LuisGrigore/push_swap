/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:25:12 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 20:33:53 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_sort.h"
#include "do_cheapest.h"
#include "node_data.h"
#include "tiny_sort.h"
#include "util.h"

static void	rotate_a(t_double_stack *stack, int n_rotations)
{
	if (n_rotations > stack->a->size / 2)
	{
		n_rotations = stack->a->size - n_rotations;
		while (n_rotations > 0)
		{
			do_rra(stack);
			n_rotations--;
		}
	}
	else
	{
		while (n_rotations > 0)
		{
			do_ra(stack);
			n_rotations--;
		}
	}
}

void	big_sort(t_double_stack *stack)
{
	t_dll_node	*current;
	t_node_data	*current_data;

	while (stack->a->size > 3)
		do_pb(stack);
	tiny_sort(stack);
	while (stack->b->size > 0)
	{
		do_cheapest(stack);
	}
	current = stack->a->head;
	current_data = (t_node_data *)current->data;
	while (current_data->index != 0)
	{
		current = current->next;
		current_data = (t_node_data *)current->data;
	}
	rotate_a(stack, current_data->position);
}
