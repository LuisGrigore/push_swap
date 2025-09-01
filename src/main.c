/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:14 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/01 16:26:10 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putstr.h"
#include "sort.h"
#include <stdio.h>

int	check_input(char **argv)
{
}

void print_stack(t_stack * stack)
{
	while(stack != NULL)
	{
		printf("%d", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		size;

	if (!check_input(argv))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	stack = new_stack_from_char_values(argv, argc);
	sort(&stack, argc - 1);
	print_stack(stack);
	free_stack(&stack);
}
