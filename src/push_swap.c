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
	push(a, 19);
	push(a, 6);
	push(a, 14);
	push(a, 8);
	push(a, 12);
	push(a, 18);
	push(a, 11);
	push(a, 16);
	push(a, 15);
	push(a, 20);
	push(a, 23);
	push(a, 22);
	push(a, 24);
	push(a, 21);
	push(a, 25);
	push(a, 28);
	push(a, 26);
	push(a, 27);
	push(a, 30);
	push(a, 29);
	push(a, 32);
	push(a, 31);
	push(a, 35);
	push(a, 34);
	push(a, 33);
	push(a, 36);
	push(a, 38);
	push(a, 37);
	push(a, 40);
	push(a, 39);
	push(a, 42);
	push(a, 41);
	push(a, 43);
	push(a, 44);
	push(a, 45);
	push(a, 47);
	push(a, 46);
	push(a, 48);
	push(a, 49);
	push(a, 50);



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
