/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:23:45 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 19:39:22 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cost.h"
#include "double_stack.h"
#include "target.h"

static int	get_cost_to_top(int pos, int size)
{
	if (pos > size / 2)
		return ((size - pos) * -1);
	return (pos);
}

t_cost	get_costs(t_double_stack *stack, int position_b, int index_b)
{
	t_cost	costs;

	costs.cost_b = get_cost_to_top(position_b, stack->b->size);
	costs.cost_a = get_cost_to_top(get_target(stack, index_b), stack->a->size);
	return (costs);
}
