#include "stack.h"
#include "../utils/errors.h"
#include <stdlib.h>

void	push(t_stack *stack, int element)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if(!new_node)
		return;
	new_node->data = element;
	new_node->next = stack->top;
	stack->top = new_node;
}
int	pop(t_stack *stack)
{
	int		element;
	t_node	*node_to_pop;

	if(is_empty(stack))
		exit(READ_FROM_EMPTY_STACK_ERROR);
	element = stack->top->data;
	node_to_pop = stack->top;
	stack->top = node_to_pop->next;
	free(node_to_pop);
	return (element);
}
int	peek(t_stack *stack)
{
	if(is_empty(stack))
		exit(READ_FROM_EMPTY_STACK_ERROR);
	return (stack->top->data);
}
t_bool	is_empty(t_stack *stack)
{
	if(stack->top == NULL)
		return (TRUE);
	return (FALSE);
}