/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_node.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:01:55 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 15:12:19 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_NODE_H
# define DLL_NODE_H

typedef struct s_dll_node
{
	int					value;
	int					index;
	int					position;
	struct s_dll_node	*next;
	struct s_dll_node	*prev;
}						t_dll_node;

t_dll_node				*new_node(int value);
void					free_node(t_dll_node *node);
int get_cost(t_dll_node *node, int list_size);

#endif
