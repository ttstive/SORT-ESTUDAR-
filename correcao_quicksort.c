#include <stdio.h>
#include <stdlib.h>

void swap(int *A, int *B);
int particao(int *V, int inicio, int fim);
void quicksort(int *V, int inicio, int fim);

void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

int particao(int *V, int inicio, int fim) {
    int pivot = V[(inicio + fim) / 2];
    int i = inicio;
    int j = fim;
    while (i <= j) {
        while (V[i] < pivot) i++;
        while (V[j] > pivot) j--;
        if (i <= j) {
            swap(&V[i], &V[j]);
            i++;
            j--;
        }
    }
    return i; // i é a posição do pivô
}

void quicksort(int *V, int inicio, int fim) {
    int pivo;
    if (inicio < fim) {
        pivo = particao(V, inicio, fim);
        quicksort(V, inicio, pivo - 1);
        quicksort(V, pivo + 1, fim);
    }
}

int main() {
    int V[15] = {4, 3, 2, 1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int N = sizeof(V) / sizeof(int);
    quicksort(V, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d\n", V[i]);
    }
    return 0;
}
