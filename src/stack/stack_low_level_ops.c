#include "stack.h"
#include "../utils/errors.h"
#include <stdlib.h>

void	push(t_stack *stack, int element)
{
	t_node	*new_node = malloc(sizeof(t_node));
	if (!new_node)
		return;

	new_node->data = element;
	new_node->next = stack->top;
	new_node->previous = NULL;
	if (stack->top != NULL)
		stack->top->previous = new_node;
	else
		stack->bottom = new_node;
	stack->top = new_node;
	stack->size++;
}
int	pop(t_stack *stack)
{
	if (is_empty(stack))
		exit(READ_FROM_EMPTY_STACK_ERROR);
	t_node *node_to_pop = stack->top;
	int element = node_to_pop->data;
	stack->top = node_to_pop->next;
	if (stack->top != NULL)
		stack->top->previous = NULL;
	else
		stack->bottom = NULL;
	free(node_to_pop);
	stack->size--;
	return element;
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

int get_value_at_index(t_stack *stack, int index)
{	
	t_node *current = stack->top;
	int current_index = 0;

	while(current)
	{
		if (current_index == index)
			return current->data;
		current = current->next;
		current_index ++;
	}
}