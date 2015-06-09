/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#ifndef _LIST_H
#define _LIST_H

typedef struct _node{
    int data;
    struct _node *link;
} node, list;

list *list_init();
list *list_append(list *head, int data);
void insert_after_node(node *n, int data);
void delete_next_node(node *n);
list *list_delete(list *head, int data);
void list_traverse(list *head);
list *list_reverse(list *head);

#endif
