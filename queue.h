/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#ifndef _QUEUE_H
#define _QUEUE_H

#define INIT_SIZE (2)

typedef struct _queue{
    int *data;
    int head;
    int tail;
    int size;
} queue;

queue *queue_init();
int queue_is_empty(queue *q);
int queue_is_full(queue *q);
void enqueue(queue *q, int data);
int dequeue(queue *q);

#endif
