/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include "queue.h"
#include <stdlib.h>

queue *queue_init(){
    queue *q;
    q = (queue *)malloc(sizeof(*q));
    q->size = INIT_SIZE;
    q->data = (int *)malloc(sizeof(*(q->data)) * q->size);
    q->head = 0;
    q->tail = 0;
    return q;
}

int queue_is_empty(queue *q){
    if (q->head == q->tail) {
        return 1;
    }
    return 0;
}

int queue_is_full(queue *q){
    if (q->head == (q->tail + 1) % q->size){
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int data){
    int i, j;
    if (queue_is_full(q)){
        q->data = (int *)realloc(q->data, sizeof(*(q->data)) * q->size *2);
        if (q->head > q->tail){
            for (i=q->size-1, j=q->size*2-1; i>=q->head; --i, --j){
                q->data[j] = q->data[i];
            }
            q->head = j;
        }
        q->size *= 2;
    }
    q->data[q->tail] = data;
    q->tail = (q->tail + 1) % q->size;
}

int dequeue(queue *q){
    int data;
    if (queue_is_empty(q)){
        return 0;
    }
    data = q->data[q->head];
    q->head = (q->head + 1) % q->size;
    return data;
}
