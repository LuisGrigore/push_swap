#include "./dual_stack.h"
#include <stdlib.h>

t_dual_stack	*init_dual_stack()
{
	t_dual_stack *dual_stack = malloc(sizeof(t_dual_stack));
	if (!dual_stack)
		return (NULL);
	dual_stack->a = init_stack();
	dual_stack->b = init_stack();
	dual_stack->op_stack = NULL;
	if (!dual_stack->a || !dual_stack->b)
	{
		destroy_dual_stack(dual_stack);
		return (NULL);
	}
	return (dual_stack);
}
void			destroy_dual_stack(t_dual_stack *dual_stack)
{
	if(!dual_stack)
		return (NULL);
	destroy_stack(dual_stack->a);
	destroy_stack(dual_stack->b);
	free (dual_stack->op_stack);
	free (dual_stack);
}
