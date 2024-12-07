#include <stdio.h>
int main(){
    int n;
    printf("Enter value of n");
    scanf("%d",&n);
    int arr[n];
    int a,i;
    for (i=0;i<n;++i){
        printf("Enter element");
        scanf("%d",&a);
        arr[i]=a;
    }
    int arr1[n];
    arr1[0]=arr[0];
    int j;
    for (j=1;j<n;++j){
        arr1[j]=arr[j]+arr1[j-1];
    }
    int k;
    for (k=0;k<n;++k){
        printf("Prefix sum is: %d \n",arr1[k]);
    }
    return 0;
}