/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:39:56 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 14:10:36 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_STACK_H
# define DOUBLE_STACK_H

# include "double_link_list.h"

typedef struct s_double_stack
{
	t_double_link_list	*a;
	t_double_link_list	*b;
}						t_double_stack;

t_double_stack			*new_double_stack(void);
t_double_stack			*new_double_stack_from_str_array(char **arr, int len);
void					free_double_stack(t_double_stack *ds);

void					do_pa(t_double_stack *stack);
void					do_pb(t_double_stack *stack);
void					do_sa(t_double_stack *stack);
void					do_sb(t_double_stack *stack);
void					do_ss(t_double_stack *stack);
void					do_ra(t_double_stack *stack);
void					do_rb(t_double_stack *stack);
void					do_rr(t_double_stack *stack);
void					do_rrr(t_double_stack *stack);
void					do_rra(t_double_stack *stack);
void					do_rrb(t_double_stack *stack);

void					sort(t_double_stack *stack);

#endif