#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "linked_list.h"

LIST* create(){
    LIST * new_list = (LIST*)malloc(sizeof(LIST));
    if(new_list != NULL){
        new_list->head = NULL;
        new_list->length = 0;
    }
    return new_list;
}

bool is_null(LIST* li){
    assert(li != NULL);
    return li->head == NULL ? true : false;
}

void insert(LIST* li, int pos, int item){
    assert(li != NULL);
    assert(pos >= 0 && pos <= li->length);

    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->item = item;
    if(pos == 0){
        new->next = li->head;
        li->head = new;
    } else {
        NODE* helper = li->head;
        for(int i = 0; i < pos - 1; i++){
            helper = helper->next;
        }
        new->next = helper->next;
        helper->next = new;
    }
    li->length++;
}

void printll(LIST* li){
    assert(li != NULL);

    NODE* helper = li->head;
    for(int i = 0; i < li->length; i++){
        printf("%d ", helper->item);
        helper = helper->next;
    }
    printf("\n");
}

int length(LIST* li){
    assert(li != NULL);
    return li->length;
}

int get(LIST* li, int pos){
    assert(li != NULL);
    assert(pos >= 0 && pos <= li->length);
    NODE* helper = li->head;
    for(int i = 0; i < pos; i++){
        helper = helper->next;
    }
    return helper->item;
}

int exclude(LIST* li, int pos){
    assert(li != NULL);
    assert(pos >= 0 && pos <= li->length);
    NODE* previous = NULL;
    NODE* helper = li->head;

    for(int i = 0; i < pos; i++){
        previous = helper;
        helper = helper->next;
    }

    if(previous == NULL){
        li->head = helper->next;
    } else{
        previous->next = helper->next;
    }
    int element = helper->item;
    li->length--;
    free(helper);
    return element;
}

void turn_free(LIST* li){
    while(!is_null(li)){
        exclude(li, 0);
    }
    free(li);
}