#include "./dual_stack.h"
#include "../stack/stack.h"

void	swap_a(t_dual_stack *dual_stack)
{
	swap_top_two(dual_stack->a);
	push_op(dual_stack->op_stack, "sa");
	dual_stack->total_ops ++;
}
void	swap_b(t_dual_stack *dual_stack)
{
	swap_top_two(dual_stack->b);
	push_op(dual_stack->op_stack, "sb");
	dual_stack->total_ops ++;
}
void	swap_a_swap_b(t_dual_stack *dual_stack)
{
	swap_top_two(dual_stack->a);
	swap_top_two(dual_stack->b);
	push_op(dual_stack->op_stack, "ss");
	dual_stack->total_ops ++;
}