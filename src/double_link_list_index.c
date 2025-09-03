/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:23:03 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 14:23:38 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_link_list.h"
#include <limits.h>
#include <stdlib.h>

static void	reset_index(t_double_link_list *list)
{
	t_dll_node	*current;

	current = list->head;
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
}

void	assign_index(t_double_link_list *list)
{
	t_dll_node	*current;
	t_dll_node	*highest;
	int			value;
	int			current_index;

	current_index = list->size;
	reset_index(list);
	while (--current_index > 0)
	{
		current = list->head;
		value = INT_MIN;
		highest = NULL;
		while (current)
		{
			if (current->index == 0 && current->value > value)
			{
				value = current->value;
				highest = current;
			}
			current = current->next;
		}
		if (highest != NULL)
			highest->index = current_index;
	}
}

int	find_highest_index(t_double_link_list *list)
{
	int			index;
	t_dll_node	*current;

	current = list->head;
	index = 0;
	while (current)
	{
		if (current->index > index)
			index = current->index;
		current = current->next;
	}
	return (index);
}
