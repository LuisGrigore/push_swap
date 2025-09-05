/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:14 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/05 12:44:38 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "node_data.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int es_entero_valido(const char *str) {
    if (*str == '\0') return 0; // vacío no válido
    
    if (*str == '+' || *str == '-') {
        str++;
        if (!isdigit(*str)) return 0; // el signo debe ir seguido de dígito
    }

    // Recorre los dígitos
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }

    return 1;
}

// Comprueba si hay repetidos en un array de enteros
int tiene_repetidos(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return 1;
        }
    }
    return 0;
}

// Función principal de validación
int validar_argumentos(int argc, char *argv[]) {
    int *numeros = malloc((argc - 1) * sizeof(int));
    if (!numeros) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (!es_entero_valido(argv[i])) {
            free(numeros);
            return 0;
        }
        numeros[i - 1] = atoi(argv[i]);
    }

    if (tiene_repetidos(numeros, argc - 1)) {
        free(numeros);
        return 0;
    }

    free(numeros);
    return 1;
}



void	print_list(t_double_link_list *list)
{
	t_dll_node	*current;
	t_node_data	*current_data;

	current = list->head;
	while (current != NULL)
	{
		current_data = (t_node_data *)current->data;
		printf("%d[%d][%d]\n", current_data->value, current_data->index, current_data->position);
		current = current->next;
	}
}



int	main(int argc, char **argv)
{
	t_double_stack	*stack;

	if (!validar_argumentos(argc, argv))
		error();
	stack = new_double_stack_from_str_array(argv + 1, argc - 1);
	sort(stack);
	//print_list(stack->a);
	free_double_stack(stack);
}
