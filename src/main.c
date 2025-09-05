/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:14 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 18:04:30 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "input_checker.h"
#include "node_data.h"
#include "util.h"

// void	print_list(t_double_link_list *list)
// {
// 	t_dll_node	*current;
// 	t_node_data	*current_data;

// 	current = list->head;
// 	while (current != NULL)
// 	{
// 		current_data = (t_node_data *)current->data;
// 		printf("%d[%d][%d]\n", current_data->value, current_data->index,
			// current_data->position);
// 		current = current->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_double_stack	*stack;

	if (!validate_input(argc, argv))
		error();
	stack = new_double_stack_from_str_array(argv + 1, argc - 1);
	sort(stack);
	// print_list(stack->a);
	free_double_stack(stack);
}
