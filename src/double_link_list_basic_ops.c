/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list_basic_ops.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:16:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 14:36:30 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_link_list.h"
#include <stdlib.h>

void	push_front(t_double_link_list *list, int value)
{
	t_dll_node	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->next = list->head;
	if (list->head)
		list->head->prev = node;
	else
		list->tail = node;
	list->head = node;
	list->size++;
}

void	push_back(t_double_link_list *list, int value)
{
	t_dll_node	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	list->size++;
}

int	pop_front(t_double_link_list *list)
{
	t_dll_node	*tmp;
	int			value;

	if (list->size == 0)
		return (0); // o error
	tmp = list->head;
	value = tmp->value;
	list->head = tmp->next;
	if (list->head)
		list->head->prev = NULL;
	else
		list->tail = NULL;
	free_node(tmp);
	list->size--;
	return (value);
}

int	pop_back(t_double_link_list *list)
{
	t_dll_node *tmp;
	int value;

	if (list->size == 0)
		return (0); // o error
	tmp = list->tail;
	value = tmp->value;
	list->tail = tmp->prev;
	if (list->tail)
		list->tail->next = NULL;
	else
		list->head = NULL;
	free_node(tmp);
	list->size--;
	return (value);
}