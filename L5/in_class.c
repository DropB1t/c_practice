#include "stdio.h"
#include "stdlib.h"

int** in_mat(int*, int*);
void free_mat(int**, int);

/* int main() {
    int r, c;
    int** m = in_mat(&r, &c);
    
    //stampa matrice:

    free_mat(m,r);
    m = NULL;
    return 0;
} */

int** in_mat(int* r, int* c) {
    scanf("%d %d", r, c);

    int** mat = (int**)malloc(*r * sizeof(int*));
    if (mat == NULL) {
        printf("Errore di memoria");
        exit(420);
    }
    for (int i = 0; i < *r; i++) {
        mat[i] = (int*)calloc(*c, sizeof(int));
        for (int j = 0; j < *c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    return mat;
}

void free_mat(int** m, int r) {
    for (int i = 0; i < r; i++) {
        free(m[i]);
    }
    free(m);
    return;
}