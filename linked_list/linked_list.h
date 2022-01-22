#include <stdbool.h>

typedef struct Node{
    int item;
    struct Node* next;
} NODE;

typedef struct linked_list{
    NODE* head;
    int length;
} LIST;

LIST* create();

bool is_null(LIST* li);

void insert(LIST* li, int pos, int item);

void printll(LIST* li);

int length(LIST* li);

int get(LIST* li, int pos);

int exclude(LIST* li, int pos);

void turn_free(LIST* li);