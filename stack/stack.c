#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "stack.h"

STACK* create(){
    STACK* newstack = (STACK*)malloc(sizeof(STACK));
    if(newstack != NULL){
        newstack->top = NULL;
        newstack->length = 0;
    }
    return newstack;
}

void push(STACK* stack, int item){
    assert(stack != NULL);
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(node != NULL){
        node->item = item;
        node->next = stack->top;
        stack->top = node;
        stack->length++;
    }
}

int pop(STACK* stack){
    assert(stack != NULL);
    assert(stack->top != NULL);

    NODE* helper = stack->top;
    int element = helper->item;
    stack->top = helper->next;
    stack->length--;
    free(helper);
    return element;
}

int top(STACK* stack){
    assert(stack != NULL);
    assert(stack->top != NULL);
    NODE* top_node = stack->top;

    return top_node->item;
}

int length(STACK* stack){
    assert(stack != NULL);
    return stack->length;
}

bool is_null(STACK* stack){
    assert(stack != NULL);
    return stack->top == NULL;
}

void free_stack(STACK* stack){
    assert(stack != NULL);
    while(!is_null(stack)){
        pop(stack);
    }
    free(stack);
}