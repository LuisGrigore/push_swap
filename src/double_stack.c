/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:40:42 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 18:13:58 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "node_data.h"
#include "util.h"
#include <limits.h>
#include <stdlib.h>

static void	free_node_data_wrapper(void *data)
{
	free_node_data((t_node_data *)data);
}

t_double_stack	*new_double_stack(void)
{
	t_double_stack	*ds;

	ds = malloc(sizeof(t_double_stack));
	if (!ds)
		return (NULL);
	ds->a = new_double_link_list();
	ds->b = new_double_link_list();
	if (!ds->a || !ds->b)
	{
		if (ds->a)
			free_double_link_list(ds->a, free_node_data_wrapper);
		if (ds->b)
			free_double_link_list(ds->b, free_node_data_wrapper);
		free(ds);
		return (NULL);
	}
	return (ds);
}

static void	assign_index(t_double_link_list *list)
{
	t_dll_node	*current;
	t_node_data	*current_data;
	t_node_data	*highest;
	int			value;
	int			current_index;

	current_index = list->size;
	while (--current_index > 0)
	{
		current = list->head;
		value = INT_MIN;
		highest = NULL;
		while (current)
		{
			current_data = (t_node_data *)current->data;
			if (current_data->index == 0 && current_data->value > value)
			{
				value = current_data->value;
				highest = current_data;
			}
			current = current->next;
		}
		if (highest != NULL)
			highest->index = current_index;
	}
}

t_double_stack	*new_double_stack_from_str_array(char **arr, int len)
{
	t_double_stack	*stack;
	long int		nb;
	int				i;

	stack = new_double_stack();
	nb = 0;
	i = 0;
	if (!stack)
		return (NULL);
	while (i < len)
	{
		nb = ft_atoi(arr[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error();
		push_back(stack->a, (void *)new_node_data(nb));
		i++;
	}
	assign_position(stack);
	assign_index(stack->a);
	return (stack);
}

void	free_double_stack(t_double_stack *ds)
{
	if (!ds)
		return ;
	if (ds->a)
		free_double_link_list(ds->a, free_node_data_wrapper);
	if (ds->b)
		free_double_link_list(ds->b, free_node_data_wrapper);
	free(ds);
}

static void	assign_position_list(t_double_link_list *list)
{
	t_dll_node	*current;
	t_node_data	*current_data;
	int			pos;

	current = list->head;
	pos = 0;
	while (current)
	{
		current_data = (t_node_data *)current->data;
		current_data->position = pos;
		pos++;
		current = current->next;
	}
}

void	assign_position(t_double_stack *stack)
{
	assign_position_list(stack->a);
	assign_position_list(stack->b);
}