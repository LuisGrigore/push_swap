/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:43:44 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 13:46:22 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_data.h"
#include <stdlib.h>

t_node_data	*new_node_data(int value)
{
	t_node_data	*data;

	data = malloc(sizeof(t_node_data));
	if (!data)
		return (NULL);
	data->value = value;
	data->index = 0;
	data->position = 0;
	return (data);
}

void	free_node_data(t_node_data *node_data)
{
	free(node_data);
}
