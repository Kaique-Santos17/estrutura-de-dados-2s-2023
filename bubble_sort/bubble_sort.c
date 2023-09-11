#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void swap(int* n1, int* n2){

    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void bubble_sort(int array[],int n){
    int i = 0;
    while(i< n){

        for(int j = 0; j <(n - 1 - i); j++){
            int ant = 0;

            if(arr[j]> array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }

        i++;
    }
    
}