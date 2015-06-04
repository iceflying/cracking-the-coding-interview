/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#ifndef _NODE_H
#define _NODE_H

typedef struct _node{
    int data;
    struct _node *link;
} node, list;

node *list_init();
node *list_append(list *head, int data);
node *list_delete(list *head, int data);
void list_traverse(list *head);

#endif
