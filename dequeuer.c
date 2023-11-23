#include "ring.h"
#include <stdio.h>


int main()
{
    queue_t* queue = init_queue(sizeof(entry_t), 32, O_RDWR);
    printf("entry size: %u, entry num: %u\n", queue->entry_size, queue->entry_num);

    for (int i=0, j=10 ;i <10; i++, j++) {
        entry_t *entry = NULL;
        int rt = dequeue(queue, &entry);
        if (rt >= 0)
            printf("entry idx: %u, entry value: %u\n", entry->idx, entry->value);
        print_queue_head_tail(queue);
    }
    print_queue_head_tail(queue);

    return 0;
}