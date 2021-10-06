struct N {
    int v;
    struct N* next;
};

typedef struct N Node;
typedef Node* List;

void insertTop(List*, int);
void insertBottom(List*, int);
void del_val(List*, int);
void print_l(List);
void print_rawL(List);
void freeListRec(List*);