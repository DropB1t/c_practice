#include <stdio.h>
#include <stdlib.h>
#include "list-4.h"

int main(){
    int n;
    scanf("%d", &n);
    List l = NULL;
    while (n > 0) {
        insertOrd(&l,n);
        scanf("%d", &n);
    }
    print_l(l);
    freeListRec(&l);
    return 0;
}