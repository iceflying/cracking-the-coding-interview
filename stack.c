/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include "stack.h"
#include <stdlib.h>

stack *stack_init(){
    stack *s;
    s = (stack *)malloc(sizeof(*s));
    s->size = INIT_SIZE;
    s->data = (int *)malloc(sizeof(*(s->data)) * s->size);
    s->top = -1;
    return s;
}

void stack_push(stack *s, int data){
    if (s->top == s->size - 1){
        s->size *= 2;
        s->data = (int *)realloc(s->data, sizeof(*(s->data)) * s->size);
    }
    s->top += 1;
    s->data[s->top] = data;
}

int stack_pop(stack *s){
    int data;
    if (stack_is_empty(s)){
        return 0;
    }
    data = s->data[s->top];
    s->top -= 1;
    return data;
}

int stack_is_empty(stack *s){
    if (s->top == -1){
        return 1;
    }
    return 0;
}
