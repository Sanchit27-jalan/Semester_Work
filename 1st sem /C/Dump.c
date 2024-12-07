#include <stdio.h>

int main(){
    int s,i,j,M,I,k,n,A[7] = {6,7,8,1,4,2,5};
    printf("Enter the sub array size\n");
    scanf("%d", &k);
    n = sizeof(A)/4;

    for (i=0; i<=(n-k); i++){
        s=0;
        for (j=i; j<i+k; j++){
            s+=A[j];
        }
        if (s>=M){
            M=s;
            I=i;
        }
    }
    printf("The final best array is as below ");
    for (i=I; i<I+k; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}