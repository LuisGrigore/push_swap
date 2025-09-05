/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:14 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 20:19:26 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "input_checker.h"
#include "util.h"


int	main(int argc, char **argv)
{
	t_double_stack	*stack;

	if (!validate_input(argc, argv))
		error();
	stack = new_double_stack_from_str_array(argv + 1, argc - 1);
	sort(stack);
	free_double_stack(stack);
}
