/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:33:50 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 21:10:44 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINK_LIST_H
# define DOUBLE_LINK_LIST_H

# include "dll_node.h"

typedef struct s_double_link_list
{
	t_dll_node		*head;
	t_dll_node		*tail;
	int				size;
}					t_double_link_list;

t_double_link_list	*new_double_link_list(void);
void				free_double_link_list(t_double_link_list *list,
						void (*free_data)(void *));

void				push_front(t_double_link_list *list, void *data);
void				push_back(t_double_link_list *list, void *data);
void				*pop_front(t_double_link_list *list);
void				*pop_back(t_double_link_list *list);

// int					is_list_sorted(t_double_link_list *list);

// void				add_element(t_double_link_list *list, void *element);
void				move_head(t_double_link_list *src,
						t_double_link_list *dest);
void				swap_front(t_double_link_list *list);
void				rotate(t_double_link_list *list);
void				reverse_rotate(t_double_link_list *list);

// int					find_highest_index(t_double_link_list *list);
// void				assign_index(t_double_link_list *list);

// void				assign_position(t_double_link_list *list);

#endif