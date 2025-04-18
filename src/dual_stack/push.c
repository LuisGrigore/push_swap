#include "./dual_stack.h"
#include "../stack/stack.h"

void	push_a(t_dual_stack *dual_stack)
{
	int	b_top;

	if(is_empty (dual_stack->b))
		return;
	b_top = pop(dual_stack->b);
	push(dual_stack->a, b_top);
	push_op(dual_stack->op_stack, "pa");
}
void	push_b(t_dual_stack *dual_stack)
{
	int	a_top;

	if(is_empty (dual_stack->a))
		return;
	a_top = pop(dual_stack->a);
	push(dual_stack->b, a_top);
	push_op(dual_stack->op_stack, "pb");
}