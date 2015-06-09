/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#ifndef _STACK_H
#define _STACK_H

#define INIT_SIZE (2)

typedef struct _stack{
    int *data;
    int top;
    int size;
} stack;

stack *stack_init();
void stack_push(stack *s, int data);
int stack_pop(stack *s);
int stack_is_empty(stack *s);

#endif
