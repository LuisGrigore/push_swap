/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:34:27 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 14:23:48 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_link_list.h"
#include <stdlib.h>

t_double_link_list	*new_double_link_list(void)
{
	t_double_link_list	*list;

	list = malloc(sizeof(t_double_link_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	free_double_link_list(t_double_link_list *list)
{
	t_dll_node	*current;
	t_dll_node	*next;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	free(list);
}

int	is_list_sorted(t_double_link_list *list)
{
	t_dll_node	*current;

	current = list->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
