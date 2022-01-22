#include <stdio.h>
#include "queue.h"

int main(){
    QUEUE* my_queue = create();

    enqueue(my_queue, 1);
    enqueue(my_queue, 2);
    enqueue(my_queue, 3);
    enqueue(my_queue, 4);

    printf("%d\n", dequeue(my_queue));
    printf("%d\n", dequeue(my_queue));
    printf("%d\n", lenght(my_queue));

    return 0;
}