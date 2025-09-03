/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_push_ops.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:18:25 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 17:02:21 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "node_data.h"
#include "util.h"

void	do_pa(t_double_stack *double_stack)
{
	move_head(double_stack->b, double_stack->a);
	assign_position(double_stack);
	ft_putstr("pa\n");
}

void	do_pb(t_double_stack *double_stack)
{
	move_head(double_stack->a, double_stack->b);
	assign_position(double_stack);
	ft_putstr("pb\n");
}
