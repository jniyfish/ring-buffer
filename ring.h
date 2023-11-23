#ifndef _RING_H_
#define _RING_H_
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

#define SHM_INIT O_CREAT | O_RDWR
#define SHM_ATTACH O_RDWR

typedef struct {
    uint32_t magic;
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

queue_t *init_queue(uint32_t entry_size, uint32_t entry_num, uint32_t init_mode);
int enqueue(queue_t *queue, uint32_t idx, uint32_t value);
int dequeue(queue_t *queue, entry_t **entry);
void print_queue_head_tail(queue_t *queue);
#endif 