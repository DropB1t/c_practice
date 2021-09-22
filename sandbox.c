#include <stdio.h>

#define N 10

void in_matrix(int [][N],int,char);
void product(int [][N],int [][N],int [][N],int);
void print_matrix(int [][N], int, char);

int main(){
    int n;
    printf("N=");
    scanf("%d",&n);

    int a[n][n], b[n][n], c[n][n];

    in_matrix(a,n,'a');
    in_matrix(b,n,'b');

    product(a,b,c,n);

    print_matrix(a,n,'a');
    print_matrix(b,n,'b');
    print_matrix(c,n,'c');

    return 0;
}

void product(int a[][N], int b[][N], int c[][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return;
}

void print_matrix(int a[][N], int n, char name){
    printf("%c:\n",name);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //printf("%c[%d][%d]=%d",name,i,j,a[i][j]);
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
    return;
}

void in_matrix(int a[][N],int n,char name){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%c[%d][%d]=",name,i,j);
            scanf("%d",&a[i][j]);
        }
    }
    return;
}



//Bubble Sort
/* #define N 100
int main(){
    float a[N];
    int dim=0,i;
    int swapped = 1;

    do{
        scanf("%f",&a[dim]);
        dim++;
    } while (a[dim-1]!=0);
    
    while(swapped){
        swapped = 0;
        for(i=0;i<dim-1;i++){
            if(a[i]<a[i+1]){
                int aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                swapped = 1;
            }
        }
    }

    for (i = 0; i < dim; i++){
        printf("%.2f ",a[i]);
    }
    printf("\n");

    return 0;
}

//Centroide di Punti distanti 100
typedef struct {
    float x;
    float y;
} Punto;

int main(){
    int n,i;
    scanf("%d",&n);
    if(n==0){
       printf("0,0");
       return 0;
    }
    Punto v[n];
    for(i=0;i<n;i++){
        scanf("%f,%f",&v[i].x,&v[i].y);
    }
    int count = 1;
    int x = v[n-1].x, y = v[n-1].y;

    for(i=0;i<n-1;i++){
        float dist = sqrt(pow(x-v[i].x,2)+pow(y-v[i].y,2));
        if(dist<100){
            x = v[i].x;
            y = v[i].y;
            count++;
        }
    }

    printf("%.1f,%.1f\n",(float)x/count,(float)y/count);

    for(i=0;i<n;i++){
        printf("%.1f,%.1f\n",v[i].x,v[i].y);
    }

}


//Esercizio con Struct e Union
typedef enum {CARDIO,DIABETE} Diagnosi;

typedef struct{
    float glicemia;
    float peso;
} VaribiliDiabete;

typedef struct{
    int fc;
    int pressione;
} VaribiliCardio;

typedef union{
    VaribiliDiabete vd;
    VaribiliCardio vc;
} VariabiliCliniche;

typedef struct{
    int id;
    VariabiliCliniche vars;
    Diagnosi d;
} Paziente;

int main(){
    int n,i;
    scanf("%d",&n);
    Paziente v[n];
    for(i=0;i<n;i++){
        scanf("%d",&v[i].id);
        scanf("%d",(int *)&(v[i].d));
        if(v[i].d == CARDIO){
            scanf("%d %d",&v[i].vars.vc.fc,&v[i].vars.vc.pressione);
        }else{
            scanf("%f %f",&v[i].vars.vd.glicemia,&v[i].vars.vd.peso);
        }
    }
    for(i=0;i<n;i++){
        if(v[i].d == v[n-1].d){
            printf("%d",v[i].id);
            if(v[i].d == CARDIO){
                printf("%d %d",v[i].vars.vc.fc,v[i].vars.vc.pressione);
            }else{
                printf("%.1f %.1f",v[i].vars.vd.glicemia,v[i].vars.vd.peso);
            }
        }
    }

} */