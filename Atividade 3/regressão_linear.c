#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numPontos = 0;
    while (fscanf(file, "%*lf,%*lf\n") != EOF) {
        numPontos++;
    }
    rewind(file);

    Ponto *pontos = (Ponto *)malloc(numPontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    double somaX = 0.0, somaY = 0.0;
    for (int i = 0; i < numPontos; i++) {
        fscanf(file, "%lf,%lf\n", &pontos[i].x, &pontos[i].y);
        somaX += pontos[i].x;
        somaY += pontos[i].y;
    }
    fclose(file);

    double mediaX = somaX / numPontos;
    double mediaY = somaY / numPontos;

    double somaXY = 0.0, somaXQuadrado = 0.0;
    for (int i = 0; i < numPontos; i++) {
        somaXY += (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
        somaXQuadrado += (pontos[i].x - mediaX) * (pontos[i].x - mediaX);
    }

    double coefAngular = somaXY / somaXQuadrado;
    double coefLinear = mediaY - coefAngular * mediaX;

    printf("Equação da regressão linear: y = %.4fx + %.4f\n", coefAngular, coefLinear);

    free(pontos);

    return 0;
}