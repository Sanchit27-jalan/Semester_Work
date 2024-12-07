#include <stdio.h>

void shellsort(int* arr, int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; ++i) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[10] = {10, 9, 8, 7, 6, 11, 4, 3, 2, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellsort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
