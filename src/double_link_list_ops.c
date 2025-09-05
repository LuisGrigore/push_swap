/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:17:44 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 20:07:36 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_link_list.h"
#include <stdlib.h>

void	move_head(t_double_link_list *src, t_double_link_list *dest)
{
	push_front(dest, pop_front(src));
}

void	rotate(t_double_link_list *list)
{
	if (!list || list->size < 2)
		return ;
	push_back(list, pop_front(list));
}

void	reverse_rotate(t_double_link_list *list)
{
	if (!list || list->size < 2)
		return ;
	push_front(list, pop_back(list));
}

void	swap_front(t_double_link_list *list)
{
	void *first;
	void *second;

	if (!list || list->size < 2)
		return ;
	first = pop_front(list);
	second = pop_front(list);

	push_front(list, first);
	push_front(list, second);
}