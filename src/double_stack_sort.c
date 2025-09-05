/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:02:54 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 20:34:51 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_sort.h"
#include "double_stack.h"
#include "node_data.h"
#include "tiny_sort.h"
#include "util.h"
#include <stdlib.h>

static int	is_sorted(t_double_stack *stack)
{
	t_dll_node	*current;
	t_node_data	*current_data;
	t_node_data	*next_data;

	current = stack->a->head;
	while (current->next != NULL)
	{
		current_data = (t_node_data *)current->data;
		next_data = (t_node_data *)current->next->data;
		if (current_data->value > next_data->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort(t_double_stack *stack)
{
	if (is_sorted(stack))
		return ;
	if (stack->a->size == 2)
		do_sa(stack);
	else if (stack->a->size == 3)
		tiny_sort(stack);
	else
	{
		big_sort(stack);
	}
}
