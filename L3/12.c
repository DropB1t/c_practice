#include "stdio.h"

void ordered_swap(int*, int*, int*);

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    ordered_swap(&a, &b, &c);
    printf("%d", a);
    printf("%d", b);
    printf("%d", c);
    return 0;
}

void ordered_swap(int* a, int* b, int* c) {
    return;
}