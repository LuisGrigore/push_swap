#include "./dual_stack.h"
#include <stdlib.h>

t_dual_stack	*init_dual_stack(t_stack *a, t_stack *b)
{
	t_dual_stack *dual_stack = malloc(sizeof(t_dual_stack));
	if (!dual_stack)
		return (NULL);
	dual_stack->a = a;
	dual_stack->b = b;
	dual_stack->op_stack = init_op_stack();
	if (!dual_stack->a || !dual_stack->b)
	{
		destroy_dual_stack(dual_stack);
		return (NULL);
	}
	return (dual_stack);
}
void	destroy_dual_stack(t_dual_stack *dual_stack)
{
	if(!dual_stack)
		return ;
	destroy_stack(dual_stack->a);
	destroy_stack(dual_stack->b);
	destroy_op_stack(dual_stack->op_stack);
	free (dual_stack);
}

char	*get_op_str(t_dual_stack *dual_stack)
{
	return to_string(dual_stack->op_stack);
}