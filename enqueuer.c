#include "ring.h"
#include <stdio.h>


int main()
{
    queue_t* queue = init_queue(sizeof(entry_t), 32);
    printf("entry size: %u, entry num: %u\n", queue->entry_size, queue->entry_num);
    for (int i=0, j=10 ;i <40; i++, j++) {
        enqueue(queue, i, j);
    }
    for (int i=0, j=10 ;i <40; i++, j++) {
        entry_t *entry = NULL;
        int rt = dequeue(queue, &entry);
        if (rt >= 0)
            printf("entry idx: %u, entry value: %u\n", entry->idx, entry->value);
    }

    for (int i=0, j=10 ;i <20; i++, j++) {
        enqueue(queue, i, j);
    }
    for (int i=0, j=10 ;i <20; i++, j++) {
        entry_t *entry = NULL;
        int rt = dequeue(queue, &entry);
        if (rt >= 0)
            printf("entry idx: %u, entry value: %u\n", entry->idx, entry->value);
    }

    return 0;
}