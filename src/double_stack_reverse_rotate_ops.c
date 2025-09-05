/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_reverse_rotate_ops.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:54:40 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 18:12:27 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "util.h"

void	do_rra(t_double_stack *double_stack)
{
	reverse_rotate(double_stack->a);
	assign_position(double_stack);
	ft_putstr("rra\n");
}

void	do_rrb(t_double_stack *double_stack)
{
	reverse_rotate(double_stack->b);
	assign_position(double_stack);
	ft_putstr("rrb\n");
}

void	do_rrr(t_double_stack *double_stack)
{
	reverse_rotate(double_stack->a);
	reverse_rotate(double_stack->b);
	assign_position(double_stack);
	ft_putstr("rrr\n");
}
