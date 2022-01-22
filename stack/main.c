#include <stdio.h>
#include "stack.h"

int main(){
    STACK* my_stack = create();

    push(my_stack, 1);
    push(my_stack, 2);
    push(my_stack, 3);
    push(my_stack, 4);

    printf("%d\n", pop(my_stack));
    printf("%d\n", pop(my_stack));
    printf("%d\n", top(my_stack));


    return 0;
}