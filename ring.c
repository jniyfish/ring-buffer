#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>       // for ftruncate
#include <unistd.h>
#include "ring.h"

queue_t *init_queue(uint32_t entry_size, uint32_t entry_num, uint32_t init_mode)
{
    uint32_t size = sizeof(queue_t) + (entry_size * entry_num);
    //queue_t* queue = (queue_t*)malloc(size);
    int shm_fd = shm_open("ring", init_mode, 0777);
    ftruncate(shm_fd, size);
    queue_t *queue = (queue_t*)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if (queue->magic != 0xf0f1f2f3) {
        queue->magic = 0xf0f1f2f3;
        queue->entry_size = entry_size;
        queue->entry_num = entry_num;
        queue->head = 0;
        queue->tail = 0;
    }
    close(shm_fd);
    print_queue_head_tail(queue);
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
    }
}

void print_queue_head_tail(queue_t *queue)
{
    printf("head: %u, tail: %u\n", queue->head, queue->tail);
}