/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:27:55 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 18:34:17 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_data.h"
#include "tiny_sort.h"

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

void	tiny_sort(t_double_stack *stack)
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
	data_head = (t_node_data *)stack->a->head->data;
	data_second = (t_node_data *)stack->a->head->next->data;
	if (data_head->index > data_second->index)
		do_sa(stack);
}
