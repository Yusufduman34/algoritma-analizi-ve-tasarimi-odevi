#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int linearSearch(int arr[], int size, int target) {
 int i;
    for ( i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // hedef bulundu
        }
    }
    return -1; // hedef bulunamad�
}

int main() {
    int arr[SIZE];
    srand(time(NULL)); // rastgele say�lar i�in tohum de�eri ayarla
    int i;
    for ( i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; // dizinin her eleman�n� rastgele 0-999 aras�nda bir say� ile doldur
    }
    int target = rand() % 1000; // aranacak hedef say�y� rastgele se�
    printf("Hedef sayi: %d\n", target);
    int result = linearSearch(arr, SIZE, target);
    if (result == -1) {
        printf("Hedef sayi bulunamadi.\n");
    } else {
        printf("Hedef sayi dizinin %d. indeksinde bulundu.\n", result);
    }
    return 0;
}

