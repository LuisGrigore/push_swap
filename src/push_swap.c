#include "dual_stack/dual_stack.h"
#include "./sort/gready_but_smart.h"
#include <stdio.h>


int main(void)
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dual_stack *dual = init_dual_stack(a, b);
	push(a, 5);
	push(a, 7);
	push(a, 9);


	push(b, 2);
	push(b, 4);
	push(b, 6);
	push(b, 8);
	push(b, 0);
	push(b, 1);


	t_dual_stack **candidates = get_candidates(dual);

	printf("%d ", pop(candidates[0]->b));
	printf("%d ", pop(candidates[0]->b));
	printf("%d ", pop(candidates[0]->b));
	printf("%d ", pop(candidates[0]->b));
	printf("%d ", pop(candidates[0]->b));
	printf("%d ", pop(candidates[0]->b));
	printf("%d ", pop(candidates[0]->b));

	printf("\n%s", get_op_str(candidates[0]));

	printf("\n%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));

	printf("\n%s", get_op_str(candidates[1]));

	printf("\n%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));

	printf("\n%s", get_op_str(candidates[2]));

	destroy_stack(a);
	return 0;
}
