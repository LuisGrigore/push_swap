/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:27:13 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/22 20:27:08 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../utils/bool.h"

typedef struct t_node {
    int data;
    struct t_node* next;
	struct t_node* previous;
} t_node;

typedef struct t_stack {
    t_node* top;
	t_node* bottom;
	int		size;
} t_stack;

t_stack	*init_stack();
void	destroy_stack(t_stack *stack);
t_stack *duplicate_stack(t_stack *original);

void	push(t_stack *stack, int element);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
t_bool	is_empty(t_stack *stack);
int get_value_at_index(t_stack *stack, int index);

void	swap_top_two(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif