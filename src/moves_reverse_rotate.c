/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:54:40 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/01 15:13:14 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include <stdlib.h>

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	before_tail = *stack;
	while (before_tail->next && before_tail->next->next)
		before_tail = before_tail->next;
	tail = before_tail->next;
	tail->next = *stack;
	*stack = tail;
	before_tail->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
