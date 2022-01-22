#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "queue.h"

QUEUE* create(){
    QUEUE* newqueue = (QUEUE*)malloc(sizeof(QUEUE));

    if(newqueue != NULL){
        newqueue->front = NULL;
        newqueue->rear = NULL;
        newqueue->length = 0;
    }
    return newqueue;
}

void enqueue(QUEUE* queue, int item){
    assert(queue != NULL);

    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(node != NULL){
        node->item = item;
        node->next = NULL;
    }
    if(queue->rear != NULL){
        queue->rear->next = node;
    } else {
        queue->front = node;
    }
    queue->rear = node;
    queue->length++;
}

int dequeue(QUEUE* queue){
    assert(queue != NULL);
    assert(queue->front != NULL);
    NODE* helper = queue->front;
    int element = helper->item;
    queue->front = helper->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    queue->length--;
    free(helper);
    return element;
}

bool is_null(QUEUE* queue){
    assert(queue != NULL);
    return queue->front == NULL;
}

int lenght(QUEUE* queue){
    assert(queue != NULL);
    return queue->length;
}

void free_queue(QUEUE* queue){
    assert(queue != NULL);
    while(!is_null(queue)){
        dequeue(queue);
    }
    free(queue);
}