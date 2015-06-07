/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *partition(list *l, int x){
    list *gep, *lp, *curr, *gepc, *lpc;
    if (l == NULL){
        return NULL;
    }
    gep = list_init();
    gepc = gep;
    lp = list_init();
    lpc = lp;
    for (curr = l->link; curr != NULL; curr = curr->link){
        if (curr->data >= x){
            gepc->link = curr;
            gepc = gepc->link;
        } else {
            lpc->link = curr;
            lpc = lpc->link;
        }
    }
    lpc->link = gep->link;
    free(gep);
    l->link = lp->link;
    free(lp);
    return l;
}

void test(list *(*func4test)(list *, int), list *l, int x){
    printf("The original list is:\n");
    list_traverse(l);
    func4test(l, x);
    printf("The list after the partition is:\n");
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

int main()
{
    list *l;
    l = build_test_list();
    test(partition, l, 3);
    return 0;
}
