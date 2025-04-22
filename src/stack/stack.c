#include "stack.h"
#include <stdlib.h>

t_stack *init_stack()
{
	t_stack *new_stack = malloc(sizeof(t_stack));
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->size = 0;
	return(new_stack);
}

void destroy_stack(t_stack *stack)
{
	if (!stack)
		return;
	while (!is_empty(stack))
	{
		pop(stack);
	}
	free(stack);
}

t_stack *duplicate_stack(t_stack *original) {
    if (!original)
		return NULL;

    t_stack *copy = init_stack();
	t_node *current = original->bottom;
    while(current)
	{
		push(copy, current->data);
		current = current->previous;
	}
    return copy;
}

