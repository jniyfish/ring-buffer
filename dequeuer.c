#include "ring.h"
#include <stdio.h>
#include <string.h>

void print_help() {
    printf("insert \"exit\" to exit program\n");
    printf("insert \"get\" to get a entry\n");
}

int main()
{
    queue_t* queue = init_queue(sizeof(entry_t), 32, O_RDWR);
    print_help();
    while(1) {
        char buf[20];
        printf("dequeuer> ");
        scanf("%s", buf);
        if (strcmp(buf, "exit") == 0) {
            printf("Exit\n");
            break;
        } else if (strcmp(buf, "get") == 0) {
            entry_t *entry = NULL;
            int rt = dequeue(queue, &entry);
            if (rt >= 0)
                printf("entry idx: %u, entry value: %u\n", entry->idx, entry->value);
            else 
                printf("dequeue failed: %d\n", rt);
            print_queue_head_tail(queue);
        } else {
            print_help();
        }
    }

    return 0;
}