#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "ring.h"

queue_t *init_queue(uint32_t entry_size, uint32_t entry_num)
{
    uint32_t size = sizeof(queue_t) + (entry_size * entry_num);
    queue_t* queue = (queue_t*)malloc(size);
    queue->entry_size = entry_size;
    queue->entry_num = entry_num;

    queue->head = 0;
    queue->tail = 0;
    return queue;
}

int enqueue(queue_t *queue, uint32_t idx, uint32_t value)
{
    if ((queue->tail+1)%queue->entry_num == queue->head) {
        printf("queue fulled\n");
        return -1;
    } else {
        entry_t *entry = (entry_t *)(queue->entry) + queue->tail;
        entry->idx = idx;
        entry->value = value;
        queue->tail = (queue->tail+1)%queue->entry_num;
        printf("enqueue success, %u\n", idx);
    }
    return 0;
}

int dequeue(queue_t *queue, entry_t **entry) {
    if (queue->tail == queue->head) {
        printf("queue is empty\n");
        return -1;
    } else {
        *entry = (entry_t *)(queue->entry) + queue->head;
        queue->head = (queue->head+1)%queue->entry_num;
        printf("dequeue success\n");
    }
}