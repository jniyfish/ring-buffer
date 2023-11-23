#ifndef _RING_H_
#define _RING_H_
#include <stdint.h>

typedef struct {
    uint32_t entry_size; // buffer size
    uint32_t entry_num;
    uint32_t head;
    uint32_t tail;
    uint8_t entry[];
} queue_t;

typedef struct {
    uint32_t idx;
    uint32_t value;
} entry_t;

queue_t *init_queue(uint32_t entry_size, uint32_t entry_num);
int enqueue(queue_t *queue, uint32_t idx, uint32_t value);
int dequeue(queue_t *queue, entry_t **entry);
#endif 