#include <stdbool.h>

typedef struct Node{
    int item;
    struct Node* next;
} NODE;

typedef struct stack{
    NODE* top;
    int length;
} STACK;

STACK* create();

void push(STACK* stack, int item);

int pop(STACK* stack);

int top(STACK* stack);

int length(STACK* stack);

bool is_null(STACK* stack);

void free_stack(STACK* stack);
