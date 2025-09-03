/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:40:42 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/03 14:45:23 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

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
			free_double_link_list(ds->a);
		if (ds->b)
			free_double_link_list(ds->b);
		free(ds);
		return (NULL);
	}
	return (ds);
}

t_double_stack	*new_double_stack_from_str_array(char **arr, int len)
{
	t_double_stack	*ds;
	long int		nb;
	int				i;

	ds = new_double_stack();
	nb = 0;
	i = 0;
	if (!ds)
		return (NULL);
	while (i < len)
	{
		nb = ft_atoi(arr[i]);
		// if (nb > INT_MAX || nb < INT_MIN)
		// 	exit_error(&stack_a, NULL);
		add_element(ds->a, nb);
		i++;
	}
	return (ds);
}

void	free_double_stack(t_double_stack *ds)
{
	if (!ds)
		return ;

	if (ds->a)
		free_double_link_list(ds->a);
	if (ds->b)
		free_double_link_list(ds->b);

	free(ds);
}