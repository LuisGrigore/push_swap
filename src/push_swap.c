#include "dual_stack/dual_stack.h"
#include "./sort/a_star.h"
#include <stdio.h>

void fill_stack_a(t_stack *a)
{
	int values[9] = {42, 17, 93, 5, 68, 21, 36, 37, -1};
	for (int i = 6; i >= 0; i--) // Se insertan para que el primero quede en el top
		push(a, values[i]);
}

void print_stack(t_stack *stack)
{
    t_node *curr = stack->top;
    printf("Stack A (top to bottom):\n");
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\nSize of stack: %d\n", stack->size);
}

int main(void)
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();

	fill_stack_a(a);

	t_dual_stack *dual = init_dual_stack(a, b);

	printf("Resolviendo con A*...\n");
	a_star_push_swap(dual);

	printf("\nStack A final:\n");
	print_stack(dual->a); // Mostramos cómo quedó el stack A tras aplicar A*

	printf("\n%s\n", *dual->op_stack);

	// (Opcional) Ver movimientos usados
	// char *result = get_op_str(dual);
	// printf("Movimientos:\n%s\n", result);
	// free(result);

	destroy_dual_stack(dual); // Libera memoria

	return 0;
}