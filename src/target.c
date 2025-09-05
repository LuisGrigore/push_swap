/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:32:06 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 20:00:20 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_data.h"
#include "target.h"
#include <limits.h>

static int	get_target_not_smallest(t_double_stack *stack, int b_idx)
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
	return (-1);
}

static int	get_target_smallest(t_double_stack *stack)
{
	t_dll_node	*current_a;
	t_node_data	*data_a;
	int			target_idx;
	int			target_pos;

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

int	get_target(t_double_stack *stack, int b_idx)
{
	int	target_pos;

	target_pos = get_target_not_smallest(stack, b_idx);
	if (target_pos != -1)
		return (target_pos);
	return (get_target_smallest(stack));
}
