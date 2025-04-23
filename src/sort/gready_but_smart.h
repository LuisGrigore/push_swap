#pragma once
#include "../dual_stack/dual_stack.h"

#pragma once
#define N_CANDIDATES 3

#pragma once
#define DEPTH 10

typedef struct t_gready_but_smart
{
	t_dual_stack	*initial_state;
	t_dual_stack	*current_state;
	t_dual_stack	*result;
	int				current_depth;
	int				n_elements;
} t_gready_but_smart;


void gready_but_smart(t_dual_stack **initial_state);
void test(t_dual_stack **initial_state);
void print(t_dual_stack *new_result);