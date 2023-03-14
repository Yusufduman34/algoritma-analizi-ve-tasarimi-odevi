#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bruteForceSort(int arr[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL));

    // Diziyi rastgele say�larla doldurma
    int i;
    for ( i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    // S�ralanmam�� diziyi yazd�rma
    printf("S�ralanmam�� dizi:\n");
    for ( i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // S�ralama i�lemini ba�latma
    clock_t t = clock();
    bruteForceSort(arr, ARRAY_SIZE);
    t = clock() - t;

    // S�ralanm�� diziyi yazd�rma
    printf("\n\nS�ralanm�� dizi:\n");
    for ( i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // Ge�en s�reyi yazd�rma
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\n\nSiralama %f saniye surdu.\n", time_taken);

    return 0;
}

