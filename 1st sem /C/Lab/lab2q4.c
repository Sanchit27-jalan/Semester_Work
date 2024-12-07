#include <stdio.h>
int main(){
    int n,a,i,q,l,r,j,b;
    printf("Enter value of n");
    scanf("%d",&n);
    int arr[n];
    for (i=0;i<n;++i){
        printf("Enter element");
        scanf("%d",&a);
        arr[i]=a;
    }
    int arr1[n];
    arr1[0]=arr[0];
    for (j=1;j<n;++j){
        arr1[j]=arr[j]+arr1[j-1];
    }
    printf("Enter value of q");
    scanf("%d",&q);
    for (j=1;j<=q;++j){
        printf("Enter lower bound");
        scanf("%d",&l);
        printf("Enter upper bound");
        scanf("%d",&r);
        b=arr1[r]-arr1[l-1];
        printf("Answer for this is : %d",b);
        printf("\n");
    }

}