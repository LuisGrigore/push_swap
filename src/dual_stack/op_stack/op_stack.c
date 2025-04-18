#include "./op_stack.h"
#include "./utils/utils.h"
#include <stdio.h>

t_op_stack *init_op_stack()
{
    t_op_stack *str_ptr = malloc(sizeof(t_op_stack *));
    if (str_ptr == NULL) {
        return NULL;
    }
    *str_ptr = malloc(1);
    if (*str_ptr == NULL) {
        free(str_ptr);
        return NULL;
    }

    (*str_ptr)[0] = '\0';
    return str_ptr;
}

void destroy_op_stack(t_op_stack *op_stack)
{
	if (op_stack != NULL && *op_stack != NULL) {
		free(*op_stack);
		*op_stack = NULL;
	}
}

void push_op(t_op_stack *op_stack, char *op)
{
    if (op == NULL || op_stack == NULL)
        return;
    if (*op_stack == NULL || (*op_stack)[0] == '\0') {
		ft_strlcat(*op_stack, op, ft_strlen(op)+1);
        return;
    }
    size_t len_a = ft_strlen(*op_stack);
    size_t len_b = ft_strlen(op);
    size_t len_total = len_a + len_b + 3; // '\n' + op + '\0'

    char *nuevo_stack = ft_str_realloc(*op_stack, len_total);
    if (nuevo_stack == NULL)
        return;

    // Insertar salto de línea manualmente
    nuevo_stack[len_a] = '\n';
    // Asegurar que la cadena termina antes de concatenar
    nuevo_stack[len_a + 1] = '\0';

    // Concatenar la nueva operación
    ft_strlcat(nuevo_stack, op, len_total);

    *op_stack = nuevo_stack;
}
char *to_string(t_op_stack *op_stack)
{
	return (*op_stack);
}