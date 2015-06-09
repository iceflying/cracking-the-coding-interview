/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include "list.h"
#include "stack.h"

typedef int BOOLEAN;

BOOLEAN is_palindrome(list *l){
    node *slow_runner, *fast_runner;
    stack *s;
    int data;
    if (l == NULL || l->link == NULL){
        return FALSE;
    }
    s = stack_init();
    slow_runner = l;
    fast_runner = l;
    while (fast_runner != NULL && fast_runner->link != NULL){
        slow_runner = slow_runner->link;
        fast_runner = fast_runner->link->link;
        stack_push(s, slow_runner->data);
    }
    if (fast_runner != NULL){
        slow_runner = slow_runner->link;
    }
    while (!stack_is_empty(s)){
        if (slow_runner->data != stack_pop(s)){
            return FALSE;
        }
        slow_runner = slow_runner->link;
    }
    return TRUE;
}

void test(BOOLEAN (*func4test)(list *), list *l){
    printf("The list is:\n");
    list_traverse(l);
    if (func4test(l)){
        printf("The list above is palindrome.\n");
    } else {
        printf("The list above is not palindrome.\n");
    }
    printf("\n");
}

int main(){
    list *l1, *l2, *l3, *l4;
    l1 = list_init();
    list_append(l1, 1);
    list_append(l1, 2);
    list_append(l1, 3);
    l2 = list_init();
    list_append(l2, 1);
    list_append(l2, 2);
    list_append(l2, 1);
    l3 = list_init();
    l4 = list_init();
    list_append(l4, 1);
    list_append(l4, 2);
    list_append(l4, 2);
    list_append(l4, 1);
    test(is_palindrome, l1);
    test(is_palindrome, l2);
    test(is_palindrome, l3);
    test(is_palindrome, l4);
    return 0;
}
