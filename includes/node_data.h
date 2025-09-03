/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:39:56 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 16:45:37 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_DATA_H
# define NODE_DATA_H

typedef struct s_node_data
{
	int		value;
	int		index;
	int		position;
}			t_node_data;

t_node_data	*new_node_data(int value);
void		free_node_data(void *node_data);

#endif