#include "list-3.h"

#include "stdio.h"
#include "stdlib.h"

void insertBottom(List* l, int x) {
    Node *prev, *succ;
    prev = NULL;
    succ = *l;
    while (succ != NULL) {
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
    if(prev != NULL)
        prev->next = new;
    if(*l == NULL)
        *l = new;
    return;
}

void insertTop(List* l, int x) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Errore di inserimento\n");
        exit(0);
    }
    new->v = x;
    new->next = *l;
    *l = new;
    return;
}

void del_val(List* l, int v) {
    Node* curr = *l;
    Node* prev = NULL;

    while (curr != NULL && curr->v != v) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL && curr->v == v) {
        curr = curr->next;
        if (prev != NULL) {
            prev->next = curr;
        }else{
            *l = curr;
        }
    }
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

void print_rawL(List l) {
    Node* c = l;
    while (c != NULL) {
        printf("%d\n", c->v);
        c = c->next;
    }
    return;
}

void freeListRec(List* l) {
    if (*l == NULL)
        return;
    freeListRec(&((*l)->next));
    free(*l);
    *l = NULL;
}