#include "stack.h"
#include <stdlib.h>

void swap_top_two(t_stack *stack)
{
	int	a;
	int b;

	if (is_empty(stack) || stack->top->next == NULL)
		return ;
	a = pop(stack);
	b = pop(stack);
	push(stack, a);
	push(stack, b);
}
void rotate_aux(t_stack *stack, int *bottom)
{
	int top_val;

	if (stack->top->next == NULL)
	{
		*bottom = pop(stack);
		return;
	}
	top_val = pop(stack);
	rotate_aux(stack, bottom);
	push(stack, top_val);
}
void rotate(t_stack *stack)
{
	int bottom;

	if (!stack || !stack->top || !stack->top->next)
		return;
	rotate_aux(stack, &bottom);
	push(stack, bottom);
}
void reverse_rotate_aux(t_stack *stack, int top)
{
	int current;

	if (!is_empty(stack))
	{
		current = pop(stack);
		reverse_rotate_aux(stack, top);
		push(stack, current);
		return ;
	}
	push(stack, top);
}
void reverse_rotate(t_stack *stack)
{
	int top;

	if (!stack || is_empty(stack) || stack->top->next == NULL)
		return;
	top = pop(stack);
	reverse_rotate_aux(stack, top);
}
