#include "./dual_stack.h"
#include "../stack/stack.h"

void	rotate_a(t_dual_stack *dual_stack)
{
	rotate(dual_stack->a);
	push_op(dual_stack->op_stack, "ra");
}
void	rotate_b(t_dual_stack *dual_stack)
{
	rotate(dual_stack->b);
	push_op(dual_stack->op_stack, "rb");
}
void	rotate_a_rotate_b(t_dual_stack *dual_stack)
{
	rotate(dual_stack->a);
	rotate(dual_stack->b);
	push_op(dual_stack->op_stack, "rr");
}