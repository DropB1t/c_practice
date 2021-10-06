struct N {
    int v;
    struct N* next;
};

typedef struct N Node;
typedef Node* List;

int lenght(List);
void insertOrd(List*, int);
void intersec(List,List,List *);
int check_val(List,int);
void print_l(List);
void freeListRec(List*);