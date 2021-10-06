struct N {
    int v;
    struct N* next;
};

typedef struct N Node;
typedef Node* List;

void in_list(List*, int);
void in_after_four(List*, int);
void insertOrd(List*, int);
void insertTop(List*, int);
void insertBottom(List*, int);

int lenght(List);
int check_val(List, int);
void del_val(List*, int);
void del_n(List*, int);
void intersec(List, List, List*);
int calcoloSomma(List);
int calcoloNElementi(List);

void print_l(List);
void print_rawL(List);

void freeListRec(List*);