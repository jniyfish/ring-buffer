#include "ring.h"
#include <stdio.h>
#include <string.h>

int main()
{
    queue_t* queue = init_queue(sizeof(entry_t), 32, SHM_INIT);
    printf("insert data index-value example: 1-1 \n");
    while(1) {
        char buf[20]={0};
        printf("enqueuer>");
        scanf("%s", buf);
        if (strcmp(buf, "exit") == 0) {
            printf("Exit\n");
            break;
        }
        uint32_t idx, value;
        sscanf(buf,"%u-%u", &idx, &value);
        enqueue(queue, idx, value);
    }

    print_queue_head_tail(queue);

    return 0;
}