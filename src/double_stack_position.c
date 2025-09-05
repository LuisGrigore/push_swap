/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:20:52 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 18:21:31 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "node_data.h"

static void	assign_position_list(t_double_link_list *list)
{
	t_dll_node	*current;
	t_node_data	*current_data;
	int			pos;

	current = list->head;
	pos = 0;
	while (current)
	{
		current_data = (t_node_data *)current->data;
		current_data->position = pos;
		pos++;
		current = current->next;
	}
}

void	assign_position(t_double_stack *stack)
{
	assign_position_list(stack->a);
	assign_position_list(stack->b);
}