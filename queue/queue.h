#include <stdbool.h>

typedef struct Node{
    int item;
    struct Node* next;
} NODE;

typedef struct queue{
    NODE* front;
    NODE* rear;
    int length;
} QUEUE;

QUEUE* create();

void enqueue(QUEUE* queue, int item);

int dequeue(QUEUE* queue);

bool is_null(QUEUE* queue);

int lenght(QUEUE* queue);

void free_queue(QUEUE* queue);
