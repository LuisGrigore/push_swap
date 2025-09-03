/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:17:44 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 15:00:44 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_link_list.h"
#include <stdlib.h>

void	add_element(t_double_link_list *list, int element)
{
	push_back(list, element);
	assign_index(list);
	assign_position(list);
}

void	move_head(t_double_link_list *src, t_double_link_list *dest)
{
	push_front(dest, pop_front(src));
	assign_index(src);
	assign_index(dest);
	assign_position(src);
	assign_position(dest);
}

void	rotate(t_double_link_list *list)
{
	if (!list || list->size < 2)
		return ;
	push_back(list, pop_front(list));
	assign_index(list);
	assign_position(list);
}

void	reverse_rotate(t_double_link_list *list)
{
	if (!list || list->size < 2)
		return ;
	push_front(list, pop_back(list));
	assign_index(list);
	assign_position(list);
}

void	swap_front(t_double_link_list *list)
{
	int first;
	int second;

	if (!list || list->size < 2)
		return ;
	first = pop_front(list);
	second = pop_front(list);

	push_front(list, first);
	push_front(list, second);
	assign_index(list);
	assign_position(list);
}