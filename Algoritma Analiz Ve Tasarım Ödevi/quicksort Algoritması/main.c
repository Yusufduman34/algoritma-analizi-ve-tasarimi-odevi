#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
        
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL));

    // Diziyi rastgele sayýlarla doldurma
    int i;
    for ( i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    // Sýralanmamýþ diziyi yazdýrma
    printf("Sýralanmamýþ dizi:\n");
    for ( i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // Sýralama iþlemini baþlatma
    clock_t t = clock();
    quickSort(arr, 0, ARRAY_SIZE - 1);
    t = clock() - t;

    // Sýralanmýþ diziyi yazdýrma
    printf("\n\nSýralanmýþ dizi:\n");
    for ( i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // Geçen süreyi yazdýrma
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\n\nSiralama %f saniye surdu.\n", time_taken);

    return 0;
}

