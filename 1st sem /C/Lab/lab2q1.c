#include<stdio.h>
int main(){
    int i,n;
    printf("Enter value of n : ");
    scanf("%d",&n);
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    for (i=2;i<n;++i){
        arr[i]=arr[i-1]+arr[i-2];
    }
    int j;
    printf("Elements of fibonacci are :\n ");
    for (j=0;j<n;++j){
        printf("%d   ",arr[j]);
    }
    return 0;
}