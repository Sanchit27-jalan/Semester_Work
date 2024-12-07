#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        int n,m;
        scanf("%d %d",&n,&m);
        int arr[n];
        for (int j=0;j<n;++j){
            scanf("%d",&arr[j]);
        }
        if (n==1 && m==1){
            printf("%d \n",0);
        }
        else{
            int sum=0;
        if (arr[m-1]>0){
            sum=sum+1;
            arr[m-1]=-arr[m-1];
        }
        if (n>m){

            if(arr[m]<0){
            sum=sum+1;
            arr[m]=-arr[m];
        }
        int arr1[n-m];
        arr1[0]=arr[m];
        int p=n-m;
        for (int k=1;k<p;++k){
            arr1[k]=arr1[k-1]+arr[k+m];
            if (arr1[k]<0){
                arr1[k]=arr1[k-1]-arr[k+m];
                sum=sum+1;
            }
        }   
        int arr2[m-1];
        arr2[0]=arr[m-1];
        for (int k=1;k<m-1;++k){
            arr2[k]=arr2[k-1]+arr[m-k-1];
            if (arr2[k]>0){
                arr2[k]=arr2[k-1]-arr[m-k-1];
                sum=sum+1;
            }
        }
        }
        else if(n==m){
            int arr2[m-1];
        arr2[0]=arr[m-1];
        for (int k=1;k<m-1;++k){
            arr2[k]=arr2[k-1]+arr[m-k-1];
            if (arr2[k]>0){
                arr2[k]=arr2[k-1]-arr[m-k-1];
                sum=sum+1;
            }
        }
        }
        printf("%d \n",sum);
        }
    }
}