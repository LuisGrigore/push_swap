#include "stack.h"
#include <stdlib.h>

void swap_top_two(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return;

	int tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
}
void rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return;

	t_node *first = stack->top;
	stack->top = first->next;
	stack->top->previous = NULL;

	stack->bottom->next = first;
	first->previous = stack->bottom;
	first->next = NULL;
	stack->bottom = first;
}
void reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return;

	t_node *last = stack->bottom;
	stack->bottom = last->previous;
	stack->bottom->next = NULL;

	last->previous = NULL;
	last->next = stack->top;
	stack->top->previous = last;
	stack->top = last;
}
