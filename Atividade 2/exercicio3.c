#include <stdio.h>
#include <string.h>

int busca_string(char *array[], int tamanho, char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1;  // Encontrou a string de busca no array
        }
    }
    return 0;  // Não encontrou a string de busca no array
}

int main() {
    char *meu_array[] = {"texto", "J", "EDA"};
    int tamanho = sizeof(meu_array) / sizeof(meu_array[0]);
    char busca[] = "EDO";

    int resultado = busca_string(meu_array, tamanho, busca);
    printf("Saída: %d\n", resultado);

    return 0;
}