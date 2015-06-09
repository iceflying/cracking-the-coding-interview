/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include "list.h"

node *find_beginning_of_loop(list *l){
    node *slow_runner, *fast_runner;
    if (l == NULL || l->link == NULL || l->link->link == NULL){
        return NULL;
    }
    slow_runner = l->link;
    fast_runner = l->link->link;
    while (slow_runner != fast_runner){
        if (fast_runner->link == NULL){
            return NULL;
        }
        slow_runner = slow_runner->link;
        fast_runner = fast_runner->link->link;
    }
    slow_runner = l;
    while (slow_runner != fast_runner){
        slow_runner = slow_runner->link;
        fast_runner = fast_runner->link;
    }
    return slow_runner;
}

void test(node *(*func4test)(list *), list *l){
    node *n;
    n = find_beginning_of_loop(l);
    printf("The beginning of the loop is %d\n", n->data);
}

list *build_list_with_loop(){
/*
 * build a list : 0 -> 1 -> 2 -> 3 -> 4 -> 2,
 * in which 2 is the beginning of the loop
 */
    list *l;
    node *curr, *loop;
    int i;
    l = list_init();
    for (curr = l, i = 0; i<5; ++i){
        insert_after_node(curr, i);
        curr = curr->link;
        if (i == 2){
            loop = curr;
        }
    }
    curr->link = loop;
    return l;
}

int main(){
    list *l;
    l = build_list_with_loop();
    test(find_beginning_of_loop, l);
    return 0;
}
