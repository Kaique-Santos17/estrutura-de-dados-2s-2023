#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void imprimir_array(int array[],int n){
    printf("\n");
    for(int i = 0; i<n; i++){
        printf("%d",array[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){

        for(int i = 1; i < argc; i++){
            array_inteiros[i - 1] = atoi(argv[i]);
        }

        int n = argc - 1;

    imprimir_array(array_inteiros, n);
    bubble_sort(array_inteiros, n);



    exit(0);
}