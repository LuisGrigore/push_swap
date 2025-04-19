#include "./dual_stack.h"
#include "../stack/stack.h"

void	reverse_rotate_a(t_dual_stack *dual_stack)
{
	reverse_rotate(dual_stack->a);
	push_op(dual_stack->op_stack, "rra");
}
void	reverse_rotate_b(t_dual_stack *dual_stack)
{
	reverse_rotate(dual_stack->b);
	push_op(dual_stack->op_stack, "rrb");
}
void	reverse_rotate_a_reverse_rotate_b(t_dual_stack *dual_stack)
{
	reverse_rotate(dual_stack->a);
	reverse_rotate(dual_stack->b);
	push_op(dual_stack->op_stack, "rrr");
}