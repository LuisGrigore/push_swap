/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:55:58 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 15:01:08 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_link_list.h"

void	assign_position(t_double_link_list *list)
{
	t_dll_node *current;
	int pos;

	current = list->head;
	pos = 0;
	while (current)
	{
		current->position = pos;
		pos ++;
		current = current->next;
	}
}