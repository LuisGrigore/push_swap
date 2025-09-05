/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:58:25 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 20:57:34 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

static int	is_valid_int(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!is_digit(*str))
			return (0);
	}
	while (*str)
	{
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	has_dup(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	are_ints(int *num, char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
		{
			free(num);
			return (0);
		}
		num[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int	validate_input(int argc, char *argv[])
{
	int	*num;

	if (argc == 1)
		return (0);
	num = malloc((argc - 1) * sizeof(int));
	if (!num)
	{
		return (0);
	}
	if (!are_ints(num, argv, argc))
		return (0);
	if (has_dup(num, argc - 1))
	{
		free(num);
		return (0);
	}
	free(num);
	return (1);
}
