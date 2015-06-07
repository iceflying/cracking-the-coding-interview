/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list *list_init(){
    node *head;
    head = (node *)malloc(sizeof(*head));
    head->data = 0;
    head->link = NULL;
    return head;
}

list *list_append(list *head, int data){
    node *new_node, *curr;
    if (head == NULL){
        return NULL;
    }
    new_node = (node *)malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->link = NULL;
    for (curr = head; curr->link != NULL; curr = curr->link);
    curr->link = new_node;
    return head;
}

void insert_after_node(node *n, int data){
    node *new_node;
    if (n == NULL){
        return;
    }
    new_node = (node *)malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->link = n->link;
    n->link = new_node;
}

void delete_next_node(node *n){
    node *tmp;
    if (n == NULL || n->link == NULL){
        return;
    }
    tmp = n->link;
    n->link = tmp->link;
    free(tmp);
}

list *list_delete(list *head, int data){
    node *curr;
    if (head == NULL){
        return NULL;
    }
    for (curr = head; curr->link != NULL; curr = curr->link){
        if (curr->link->data == data){
            delete_next_node(curr);
        }
    }
    return head;
}

void list_traverse(list *head){
    node *curr;
    if (head == NULL){
        printf("The list does not exist!\n");
        return ;
    }
    if (head->link == NULL){
        printf("The list is empty.\n");
        return ;
    }
    for (curr = head->link; curr != NULL; curr = curr->link){
        printf("%d ", curr->data);
    }
    printf("\n");
    return ;
}

list *list_reverse(list *head){
    list *rl;
    node *curr;
    if (head == NULL){
        return NULL;
    }
    rl = list_init();
    for (curr = head->link; curr != NULL; curr = curr->link){
        insert_after_node(rl, curr->data);
    }
    return rl;
}
