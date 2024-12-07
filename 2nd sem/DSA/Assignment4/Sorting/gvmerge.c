#include <stdio.h>

void copy_array(int *A, int start, int end, int *B) {
    for(int i = start; i <= end; i++) {
        B[i-start] = A[i];
    }
}

void merge(int *L, int sL, int* R, int sR, int *A) {

    int l = 0, r = 0, c = 0;

    while(c <= sL + sR -1) {
        if (r == sR  ) {
            A[c++] = L[l++];
            continue;
        }

        if (l == sL ) {
            A[c++] = R[r++];
            continue;
        }

        if (L[l] < R[r]) {
            A[c++] = L[l++];
        } else if (L[l] >= R[r]) {
            A[c++] = R[r++];
        }
    }

}

void sort(int *A, int len) {
    if (len == 1) {
        return;
    } else {
        int mid = len/2;
        int L [ mid], R [ len - mid ];
        copy_array(A, 0, mid, L);
        copy_array(A, mid, len, R);
        sort(L, mid);
        sort(R,len - mid);
        merge(L, mid, R, len-mid, A);
    }
}

int main()
{
     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);
    for(int i = 0; i <n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}