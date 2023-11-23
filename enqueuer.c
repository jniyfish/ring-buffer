#include "ring.h"
#include <stdio.h>


int main()
{
    queue_t* queue = init_queue(sizeof(entry_t), 32, SHM_INIT);
    printf("entry size: %u, entry num: %u\n", queue->entry_size, queue->entry_num);
    for (int i=0, j=10 ;i <10; i++, j++) {
        enqueue(queue, i, j);
        print_queue_head_tail(queue);
    }

    print_queue_head_tail(queue);

    return 0;
}