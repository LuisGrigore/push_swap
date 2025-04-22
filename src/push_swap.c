#include "dual_stack/dual_stack.h"
#include "./sort/gready_but_smart.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dual_stack *dual = init_dual_stack(a, b);

	push(a, 3);
	push(a, 7);
	push(a, 5);
	push(a, 10);
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
	printf("\n%d", candidates[0]->total_ops);

	printf("\n%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));
	printf("%d ", pop(candidates[1]->b));

	printf("\n%s", get_op_str(candidates[1]));
	printf("\n%d", candidates[1]->total_ops);

	printf("\n%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));
	printf("%d ", pop(candidates[2]->b));

	printf("\n%s", get_op_str(candidates[2]));
	printf("\n%d", candidates[2]->total_ops);

	printf("\n%d ", pop(candidates[3]->b));
	printf("%d ", pop(candidates[3]->b));
	printf("%d ", pop(candidates[3]->b));
	printf("%d ", pop(candidates[3]->b));
	printf("%d ", pop(candidates[3]->b));
	printf("%d ", pop(candidates[3]->b));
	printf("%d ", pop(candidates[3]->b));

	printf("\n%s", get_op_str(candidates[3]));
	printf("\n%d", candidates[3]->total_ops);


	destroy_dual_stack(dual);
	destroy_dual_stack(candidates[0]);
	destroy_dual_stack(candidates[1]);
	destroy_dual_stack(candidates[2]);
	destroy_dual_stack(candidates[3]);
	free(candidates);
	return 0;
}
