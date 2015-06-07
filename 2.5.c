/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include "list.h"

list *add_lists(list *l1, list *l2){
// Reverse storage
    node *curr1, *curr2;
    int sum, carry;
    list *res;
    if (l1 == NULL && l1->link == NULL){
        return l2;
    }
    if (l2 == NULL && l2->link == NULL){
        return l1;
    }
    res = list_init();
    for (curr1 = l1->link, curr2 = l2->link, carry = 0;
         curr1 != NULL && curr2 != NULL;
         curr1 = curr1->link, curr2 = curr2->link){
        sum = curr1->data + curr2->data + carry;
        list_append(res, sum % 10);
        carry = sum / 10;
    }
    if (curr1 == NULL){
        for (; curr2 != NULL; curr2 = curr2->link){
            sum = curr2->data + carry;
            list_append(res, sum % 10);
            carry = sum / 10;
        }
    } else {
        for (; curr1 != NULL; curr1 = curr1->link){
            sum = curr1->data + carry;
            list_append(res, sum % 10);
            carry = sum / 10;
        }
    }
    return res;
}

list *add_lists2(list *l1, list *l2){
    list *rl1, *rl2, *res;
    rl1 = list_reverse(l1);
    rl2 = list_reverse(l2);
    res = add_lists(rl1, rl2);
    return list_reverse(res);
}

void test(list *(*func4test)(list *, list *), list *l1, list *l2){
    list *l;
    printf("List 1 is:\n");
    list_traverse(l1);
    printf("List 2 is:\n");
    list_traverse(l2);
    l = func4test(l1, l2);
    printf("The sum list is:\n");
    list_traverse(l);
}

int main(){
    list *l1, *l2;
    l1 = list_init();
    list_append(l1, 7);
    list_append(l1, 1);
    list_append(l1, 6);
    l2 = list_init();
    list_append(l2, 5);
    list_append(l2, 9);
    list_append(l2, 9);
    list_append(l2, 3);
    list_append(l2, 5);
    test(add_lists, l1, l2);
    test(add_lists2, l1, l2);
    return 0;
}
