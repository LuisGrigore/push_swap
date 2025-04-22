#pragma once
# include "../stack/stack.h"
# include "./op_stack/op_stack.h"

typedef struct t_dual_stack
{
	t_stack *a;
	t_stack *b;
	t_op_stack *op_stack;
} t_dual_stack;

t_dual_stack	*init_dual_stack(t_stack *a, t_stack *b);
void			destroy_dual_stack(t_dual_stack *dual_stack);
t_dual_stack *duplicate_dual_stack(t_dual_stack *original);
char			*get_op_str(t_dual_stack *dual_stack);

void			swap_a(t_dual_stack *dual_stack);
void			swap_b(t_dual_stack *dual_stack);
void			swap_a_swap_b(t_dual_stack *dual_stack);

void			push_a(t_dual_stack *dual_stack);
void			push_b(t_dual_stack *dual_stack);

void			rotate_a(t_dual_stack *dual_stack);
void			rotate_b(t_dual_stack *dual_stack);
void			rotate_a_rotate_b(t_dual_stack *dual_stack);

void			reverse_rotate_a(t_dual_stack *dual_stack);
void			reverse_rotate_b(t_dual_stack *dual_stack);
void			reverse_rotate_a_reverse_rotate_b(t_dual_stack *dual_stack);
