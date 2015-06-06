/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include "list.h"

node *nth_to_last(list *l, int n){
    node *nth, *last;
    int i;
    if (l == NULL && l->link == NULL){
        return NULL;
    }
    for (i=0, last = l; i < n; ++i){
        last = last->link;
        if (last == NULL){
            return NULL;
        }
    }
    for (nth = l; last != NULL; last = last->link, nth = nth->link);
    return nth;
}

void test(node *(*func4test)(list *, int), list *l, int n){
    node *nth;
    nth = nth_to_last(l, n);
    printf("The list is:\n");
    list_traverse(l);
    printf("The value of the %dth node from bottom is %d\n", n, nth->data);
}

list *build_test_list(){
    list *l;
    l = list_init();
    list_append(l, 1);
    list_append(l, 2);
    list_append(l, 3);
    list_append(l, 1);
    list_append(l, 1);
    list_append(l, 4);
    list_append(l, 3);
    return l;
}

int main(){
    list *l;
    int n = 6;
    l = build_test_list();
    test(nth_to_last, l, n);
    return 0;
}
