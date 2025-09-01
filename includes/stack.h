/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:01:55 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/01 16:44:03 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*get_stack_tail(t_stack *stack);
void				free_stack(t_stack **stack);
t_stack				*new_stack_from_char_values(char **values, int size);

#endif