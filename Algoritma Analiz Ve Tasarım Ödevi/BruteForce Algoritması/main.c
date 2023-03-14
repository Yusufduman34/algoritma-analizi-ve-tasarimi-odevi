#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int bruteForce(int arr[], int size) {
    int max = arr[0];
    int i,j;
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
        }
    }
    return max;
}

int main() {
    int arr[SIZE];
    srand(time(NULL)); // rastgele sayýlar için tohum deðeri ayarla
    int i;
    for ( i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; // dizinin her elemanýný rastgele 0-999 arasýnda bir sayý ile doldur
    }
    clock_t start = clock(); // algoritmanýn çalýþma süresini ölçmek için zaman ölçüsü al
    int result = bruteForce(arr, SIZE);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // geçen süreyi saniyeye çevir
    printf("En buyuk sayi: %d\n", result);
    printf("Calisma suresi: %f saniye\n", time_taken);
    return 0;
}

