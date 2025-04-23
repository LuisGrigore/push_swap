#include "dual_stack/dual_stack.h"
#include "./sort/gready_but_smart.h"
#include "./sort/move/move.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dual_stack *dual = init_dual_stack(a, b);

	push(a, 4);
	push(a, 2);
	push(a, 1);
	push(a, 9);
	push(a, 5);
	push(a, 10);
	push(a, 17);
	push(a, 3);
	push(a, 13);
	push(a, 7);
	push(a, 11);
	push(a, 12);
	push(a, 15);
	push(a, 19);
	push(a, 6);
	push(a, 14);
	push(a, 20);
	push(a, 8);
	push(a, 16);



	gready_but_smart(&dual);
	//test(&dual);

	print(dual);


	printf("\n%d ", dual->total_ops);
	//printf("%d ", pop(dual->b));
	//printf("%d ", pop(dual->b));
	//printf("%d ", pop(dual->b));
	//printf("%d ", pop(dual->b));
	//printf("%d ", pop(dual->b));
	//printf("%d ", pop(dual->b));
	//printf("%d ", pop(dual->b));
	//printf("%d ", pop(dual->b));

	destroy_dual_stack(dual);
	return 0;
}
