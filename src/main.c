/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:14 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 14:02:31 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// /* Comprueba si la cadena representa un número válido */
// static bool	is_valid_number(const char *str)
// {
// 	if (*str == '+' || *str == '-')
// 		str++;
// 	if (!*str) // no puede estar vacío después del signo
// 		return (false);
// 	while (*str)
// 	{
// 		if (!isdigit((unsigned char)*str))
// 			return (false);
// 		str++;
// 	}
// 	return (true);
// }

// /* Comprueba si el número cabe en un int */
// static bool	is_within_int(const char *str)
// {
// 	long	val;

// 	val = strtol(str, NULL, 10);
// 	return (val >= INT_MIN && val <= INT_MAX);
// }

// /* Comprueba duplicados */
// static bool	has_duplicates(int argc, char **argv)
// {
// 	for (int i = 1; i < argc; i++)
// 	{
// 		for (int j = i + 1; j < argc; j++)
// 		{
// 			if (strcmp(argv[i], argv[j]) == 0)
// 				return (true);
// 		}
// 	}
// 	return (false);
// }

// /* Función principal de validación */
// bool	validate_args(int argc, char **argv)
// {
// 	for (int i = 1; i < argc; i++)
// 	{
// 		if (!is_valid_number(argv[i]))
// 			return (false);
// 		if (!is_within_int(argv[i]))
// 			return (false);
// 	}
// 	if (has_duplicates(argc, argv))
// 		return (false);
// 	return (true);
// }

static int	str_to_int(const char *str, int *out)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str) // string vacío después del signo
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0); // no es un dígito válido
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0); // overflow
		str++;
	}
	*out = (int)(num * sign);
	return (1); // éxito
}

int	*char_array_to_int_array(char **arr, int size)
{
	int	*res;
	int	value;
	int	i;

	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL); // error malloc
	i = 0;
	while (i < size)
	{
		if (!str_to_int(arr[i], &value))
		{
			free(res);
			return (NULL); // error en conversión
		}
		res[i] = value;
		i++;
	}
	return (res);
}

void	print_list(t_double_link_list *list)
{
	t_dll_node	*current;

	current = list->head;
	while (current != NULL)
	{
		printf("%d[%d]", current->value, current->index);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_double_stack	*stack;
	int				size;

	// if (!check_input(argv))
	// {
	// 	ft_putstr("Error\n");
	// 	exit(1);
	// }
	stack = new_double_stack_from_str_array(argv + 1, argc - 1);
	sort(stack);
	print_list(stack->a);
	// free_double_stack(stack);
}
