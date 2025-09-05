/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_swap_ops.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:46:58 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 18:13:41 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "util.h"

void	do_sa(t_double_stack *double_stack)
{
	swap_front(double_stack->a);
	ft_putstr("sa\n");
}

void	do_sb(t_double_stack *double_stack)
{
	swap_front(double_stack->b);
	ft_putstr("sb\n");
}

void	do_ss(t_double_stack *double_stack)
{
	swap_front(double_stack->a);
	swap_front(double_stack->b);
	ft_putstr("ss\n");
}
