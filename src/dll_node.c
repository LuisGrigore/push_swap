/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:53:46 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 15:14:48 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll_node.h"
#include <stdlib.h>

t_dll_node	*new_node(int value)
{
	t_dll_node	*node;

	node = malloc(sizeof(t_dll_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	node->position = 0;
	return (node);
}

void	free_node(t_dll_node *node)
{
	if (node)
		free(node);
}

int get_cost(t_dll_node *node, int list_size)
{
	int cost_a;
	int cost_b;
	
	if (node->position > list_size/2)
		cost_b = (list_size - node->position) * -1;
	else
		cost_b = node->position;
	
}
