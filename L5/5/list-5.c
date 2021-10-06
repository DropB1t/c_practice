#include "list-5.h"

#include "stdio.h"
#include "stdlib.h"

void insertOrd(List* l, int x) {
    Node *prev, *succ;
    prev = NULL;
    succ = *l;
    while (succ != NULL && succ->v < x) {
        prev = succ;
        succ = succ->next;
    }
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Errore di inserimento\n");
        exit(0);
    }
    new->v = x;
    new->next = succ;
    if (prev != NULL)
        prev->next = new;
    else
        *l = new;
    return;
}

void print_l(List l) {
    Node* c = l;
    printf("List: ");
    while (c != NULL) {
        printf("%d -> ", c->v);
        c = c->next;
    }
    printf("NULL\n");
    return;
}

int check_val(List l, int v) {
    Node* c = l;
    while (c != NULL) {
        if (c->v == v) {
            return 1;
        }
        c = c->next;
    }
    return -1;
}

void intersec(List l1, List l2, List* l) {
    if (lenght(l1) < lenght(l2)) {
        Node* temp = l1;
        l1 = l2;
        l2 = temp;
    }
    Node* c = l1;

    while (c != NULL) {
        if (check_val(l2, c->v) == 1 && check_val(*l, c->v) == -1){
            insertOrd(&(*l),c->v);
        }
        c = c->next;
    }
    return;
}

int lenght(List l) {
    Node* c = l;
    int cout = 0;
    while (c != NULL) {
        cout++;
        c = c->next;
    }
    return cout;
}

void freeListRec(List* l) {
    if (*l == NULL)
        return;
    freeListRec(&((*l)->next));
    free(*l);
    *l = NULL;
}