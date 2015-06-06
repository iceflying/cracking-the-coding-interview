/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void delete_node(node *n){
    node *tmp;
    if (n == NULL || n->link == NULL){
        return ;
    }
    tmp = n->link;
    n->data = tmp->data;
    n->link = tmp->link;
    free(n);
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
    int i;
    node *curr;
    l = build_test_list();
    printf("The original list is:\n");
    list_traverse(l);
    for (i=0, curr = l; i<3; ++i){
        curr = curr->link;
    }
    delete_node(curr);
    printf("The list deleted the third node is:\n");
    list_traverse(l);
    return 0;
}
