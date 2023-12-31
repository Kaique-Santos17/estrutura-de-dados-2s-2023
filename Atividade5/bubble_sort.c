#include "bubble_sort.h"

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char *arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}