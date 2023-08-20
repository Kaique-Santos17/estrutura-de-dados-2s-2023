#include <stdio.h>

int soma_array(int array[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

int main() {
    int meu_array[] = {5, 7, 9, 6};
    int tamanho = sizeof(meu_array) / sizeof(meu_array[0]);

    int resultado = soma_array(meu_array, tamanho);
    printf("Saída: %d\n", resultado);

    return 0;
}