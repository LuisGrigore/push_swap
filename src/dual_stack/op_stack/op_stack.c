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
		free(op_stack);
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
    size_t len_total = len_a + len_b + 2;

    char *nuevo_stack = ft_str_realloc(*op_stack, len_total);
    if (nuevo_stack == NULL)
        return;

    nuevo_stack[len_a] = '\n';
    nuevo_stack[len_a + 1] = '\0';
    ft_strlcat(nuevo_stack, op, len_total);
    *op_stack = nuevo_stack;
}
char *to_string(t_op_stack *op_stack)
{
	return (*op_stack);
}

t_op_stack *duplicate_op_stack(t_op_stack *original) {
    if (!original) return NULL;

    // Contar cuántos hay
    int count = 0;
    while (original[count])
        count++;

    t_op_stack *copy = malloc((count + 1) * sizeof(t_op_stack));

    for (int i = 0; i < count; i++) {
        copy[i] = ft_strdup(original[i]);
    }
    copy[count] = NULL; // Terminar con NULL como el original

    return copy;
}