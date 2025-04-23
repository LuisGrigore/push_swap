#pragma once
#include "../../dual_stack/dual_stack.h"

void move(t_dual_stack *dual, int index_in_a);

void rotate_b_for_insert(t_dual_stack *state, int value);
void put_index_on_top_b(t_dual_stack *state, int index);
void perform_move(t_dual_stack *state, int index);