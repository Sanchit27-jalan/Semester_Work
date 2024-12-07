#include <stdio.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr1[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr1[i]);
    }
    if(n==k){
        for(int i=0;i<n;++i){
        printf("%d ",arr1[i]);
    }
    }
    else if(k==1){
        for(int i=0;i<n;++i){
            printf("%d \n",arr1[i]);
        }
    }
}