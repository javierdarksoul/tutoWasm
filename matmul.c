#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void llenar(int* M, int n, int value){
    for (int i=0;i<n;i++){
        M[i]=value;
    }
}
void printmat(int *M,int n){
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             printf("| %d ",M[(i*n)+j]);
        }
        printf("\n");
    }
    printf("\n");

}
int main(int argc, char **argv){ 
    clock_t t_ini, t_fin;
    double secs;
    t_ini=clock();
    int n=10;
    //code here
    
    int *A=(int*)malloc(sizeof(int)*n*n);
    int *B=(int*)malloc(sizeof(int)*n*n);
    int *C=(int*)malloc(sizeof(int)*n*n);

    llenar(A,n*n,4);
    //printmat(&A,n);
    llenar(B,n*n,2);
    llenar(C,n*n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                C[(i*n)+j]=C[(i*n)+j]+ ( A[(i*n)+k] * B[(k*n)+j] );
            }
        }
    }
    printmat(A,n);
    printmat(B,n);
    printmat(C,n);
    //end code
    t_fin=clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", secs * 1000.0);
    return 0;
}


