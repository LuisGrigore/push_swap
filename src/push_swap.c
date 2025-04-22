#include "dual_stack/dual_stack.h"
#include <stdio.h>


int main(void)
{
	t_stack *a = init_stack();
	push(a, 3);
	push(a, 2);
	push(a, 1);

	printf("%d ", pop(a));
	printf("%d ", pop(a));
	printf("%d ", pop(a));

	push(a, 3);
	push(a, 2);
	push(a, 1);

	swap_top_two(a);

	printf("\n%d ", pop(a));
	printf("%d ", pop(a));
	printf("%d ", pop(a));

	destroy_stack(a);
	return 0;
}