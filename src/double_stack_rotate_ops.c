/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_rotate_ops.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:50:12 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 14:12:13 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "util.h"
#include <stdlib.h>

void	do_ra(t_double_stack *double_stack)
{
	rotate(double_stack->a);
	ft_putstr("ra\n");
}

void	do_rb(t_double_stack *double_stack)
{
	rotate(double_stack->b);
	ft_putstr("rb\n");
}

void	do_rr(t_double_stack *double_stack)
{
	rotate(double_stack->a);
	rotate(double_stack->b);
	ft_putstr("rr\n");
}
