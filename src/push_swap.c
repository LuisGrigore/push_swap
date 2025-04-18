#include "dual_stack/dual_stack.h"
#include <stdio.h>

int main()
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dual_stack *dual_stack = init_dual_stack(a, b);
	push(a, 1);
	push(a, 2);
	push(a, 3);
	push(a, 4);

	/*swap_a(dual_stack);
	swap_a(dual_stack);
	swap_a(dual_stack);*/

	push_b(dual_stack);

	printf("%s", get_op_str(dual_stack));
	printf("%d", pop(dual_stack->a));
	printf("%d", pop(dual_stack->b));
	destroy_dual_stack(dual_stack);
	return 0;
}