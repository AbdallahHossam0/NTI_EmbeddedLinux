#include "add.h"
#include "sub.h"
#include <stdio.h>

int main(void){

    int res1 = add(5, 1);
    int res2 = sub(6, 1);

    printf("res1: %d\n", res1);
    printf("res2: %d\n", res2);
    
    return 0;
}