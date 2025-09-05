/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:34:27 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 11:30:11 by lgrigore         ###   ########.fr       */
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

static void	free_node_list(t_dll_node *node, void (*free_data)(void *))
{
	if (!node)
		return ;
	if (free_data && node->data)
		free_data(node->data); // liberar contenido si se especifica
	free(node);                // liberar el nodo en sí
}

void	free_double_link_list(t_double_link_list *list,
		void (*free_data)(void *))
{

	if (!list)
		return ;
	while (list->size >0)
	{
		free_data(pop_front(list));
	}
	free(list);
}

