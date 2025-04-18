#pragma once

typedef char *t_op_stack;

t_op_stack *init_op_stack();
void destroy_op_stack(t_op_stack *op_stack);
void push_op(t_op_stack *op_stack, char *op);
char *to_string(t_op_stack *op_stack);