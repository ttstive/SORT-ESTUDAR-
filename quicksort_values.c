#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VERDADEIRO 1
#define FALSO 0

void swap( int *A, int *B);
int particao(int *V, int inicio, int fim);
void quicksort(int *V, int inicio, int fim);

int main (){
    system("cls");
    int V[14] = {11,9, 10, 8,7,6,5,4,3,2,1};
    int N = sizeof(V)/ sizeof(int);
    quicksort(V,0,N -1);
    for (int i = 0; i <N; i++){
        printf("%d", V[i]);
        printf("\n");
    }
}
void swap( int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}


int particao (int *V, int inicio, int fim){
    int pivo = V[(inicio + fim) / 2];
    int i = inicio +1;
    int j = fim;
    while (i <= j){
        while(i <= inicio && V[i] < pivo)
            i++;
        while (j >= 0 && V[j] > pivo){
            j--;
        if (i <= j){
            swap(&V[i], &V[j]);
        
        }
        }
    }
    swap (&V[inicio], &V[j]);
    return i; // i é a posição do pivô
}

void (quicksort (int *V, int inicio, int fim)){
    int pivo;
    if (inicio < fim){
        pivo = particao (V, inicio, fim);
        quicksort(V, inicio, pivo - 1);
        quicksort(V, pivo + 1, fim);
    }
}
