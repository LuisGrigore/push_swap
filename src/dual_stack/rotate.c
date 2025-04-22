#include "./dual_stack.h"
#include "../stack/stack.h"

void	rotate_a(t_dual_stack *dual_stack)
{
	rotate(dual_stack->a);
	push_op(dual_stack->op_stack, "ra");
	dual_stack->total_ops ++;
}
void	rotate_b(t_dual_stack *dual_stack)
{
	rotate(dual_stack->b);
	push_op(dual_stack->op_stack, "rb");
	dual_stack->total_ops ++;
}
void	rotate_a_rotate_b(t_dual_stack *dual_stack)
{
	rotate(dual_stack->a);
	rotate(dual_stack->b);
	push_op(dual_stack->op_stack, "rr");
	dual_stack->total_ops ++;
}