#include <stdio.h>

void menor_maior_array(int array[], int tamanho, int *menor, int *maior) {
    *menor = array[0];
    *maior = array[0];

    for (int i = 1; i < tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        }
        if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
    int meu_array[] = {5, 7, 9, 6};
    int tamanho = sizeof(meu_array) / sizeof(meu_array[0]);

    int menor, maior;
    menor_maior_array(meu_array, tamanho, &menor, &maior);
    printf("Saída: %d, %d\n", menor, maior);

    return 0;
}