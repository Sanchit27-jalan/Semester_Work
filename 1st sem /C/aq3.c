#include <stdio.h>
int main(){
    int t,n,i,j;
    scanf("%d",&t);
    for (int k=0;k<t;++k){
        scanf("%d",&n);
        int arr[n];
        for (j=0;j<n;++j){
            scanf("%d",&arr[j]);
        }
        int sum=arr[0]+arr[n-1];
        for (i=0;i<(n-1);++i){
            int k=arr[i]+arr[i+1];
            if (k>sum){
                 sum=k;
                  }
        }
        printf("%d \n",sum);
    }
}