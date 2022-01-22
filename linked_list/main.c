#include <stdio.h>
#include "linked_list.h"


int main(){
    LIST* li = create();

    if(is_null(li)){
        printf("OK... the list is NULL\n");
    }
    else{
        printf("Ops.. WTF?\n");
    }

    insert(li, 0, 3);
    insert(li, 0, 2);
    insert(li, 0, 1);
    printll(li);
    // printf("\n%d", get(li, 1));
    exclude(li, 1);
    printll(li);
    turn_free(li);
    printll(li);

    return 0;
}