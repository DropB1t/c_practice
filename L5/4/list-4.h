struct N {
    int v;
    struct N* next;
};

typedef struct N Node;
typedef Node* List;

void insertOrd(List*, int);
void print_l(List);
void freeListRec(List*);