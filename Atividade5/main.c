#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso correto: %s arquivo_de_entrada.txt\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char outputFileName[100];

    // Abre o arquivo de entrada
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Lê as palavras do arquivo de entrada
    char *words[100]; // Supõe que haverá no máximo 100 palavras
    int numWords = 0;

    char word[100]; // Supõe que cada palavra terá no máximo 100 caracteres

    while (fscanf(inputFile, "%s", word) != EOF) {
        words[numWords] = strdup(word);
        numWords++;
    }

    fclose(inputFile);

    // Ordena as palavras usando o algoritmo Bubble Sort
    bubbleSort(words, numWords);

    // Cria o nome do arquivo de saída
    snprintf(outputFileName, sizeof(outputFileName), "%s_ordenado.txt", inputFileName);

    // Abre o arquivo de saída
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    // Escreve as palavras ordenadas no arquivo de saída
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(outputFile);

    printf("As palavras foram ordenadas e salvas em %s\n", outputFileName);

    return 0;
}