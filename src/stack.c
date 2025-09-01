/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:53:46 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/01 15:52:16 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>
#include <stdlib.h>
#include "ft_putstr.h"
#include <stdio.h>

t_stack	*get_stack_tail(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);

	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_tail(*stack);
	tail->next = new;
}

t_stack	*new_stack_from_char_values(char **values, int size)
{
	t_stack		*stack;
	long int	nb;
	int			i;

	stack = NULL;
	nb = 0;
	i = 1;
	while (i < size)
	{
		nb = ft_atoi(values[i]);
		//if (nb > INT_MAX || nb < INT_MIN)
			//exit_error(&stack, NULL);
		if (i == 1)
			stack = stack_new((int)nb);
		else
			stack_add_bottom(&stack, stack_new((int)nb));
		i++;
	}
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
