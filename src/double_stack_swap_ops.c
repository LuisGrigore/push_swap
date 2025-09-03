/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_swap_ops.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:46:58 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 17:02:43 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "node_data.h"
#include "util.h"
#include <stdlib.h>

void	do_sa(t_double_stack *double_stack)
{
	swap_front(double_stack->a);
	ft_putstr("sa\n");
}

void	do_sb(t_double_stack *double_stack)
{
	swap_front(double_stack);
	ft_putstr("sb\n");
}

void	do_ss(t_double_stack *double_stack)
{
	swap_front(double_stack);
	swap_front(double_stack);
	ft_putstr("ss\n");
}
