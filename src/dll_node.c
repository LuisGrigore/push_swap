/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:53:46 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 21:14:44 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll_node.h"
#include <stdlib.h>

t_dll_node	*new_node(void *data)
{
	t_dll_node	*node;

	node = malloc(sizeof(t_dll_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_node(t_dll_node *node)
{
	if (!node)
		return ;
	free(node); // liberar el nodo en sí
}
