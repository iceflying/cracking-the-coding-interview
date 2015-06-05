/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include "list.h"

void delete_dups(list *l){
    node *curr, *runner;
    int data;
    if (l == NULL){
        return ;
    }
    for (curr = l->link; curr != NULL; curr = curr->link){
        data = curr->data;
        if (curr->link == NULL){
            return;
        }
        for (runner = curr; runner->link != NULL; ){
            if (runner->link->data == data){
                delete_next_node(runner);
            } else {
                runner = runner->link;
            }
        }
    }
}

void test(void (*func4test)(list *), list *l){
    printf("The origin list is :\n");
    list_traverse(l);
    func4test(l);
    printf("The list without duplicate values is:\n");
    list_traverse(l);
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
    l = build_test_list();
    test(delete_dups, l);
    return 0;
}
