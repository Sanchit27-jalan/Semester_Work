#include <stdio.h>
#include<math.h>
int det(int n,int arr[n][n]){
    int sum=0;
    if (n==1){
        return(arr[0][0]);
    }
    else{
        for (int i=0;i<n;++i){
        int a[n-1][n-1];
        for (int j=1;j<n;++j){
            for(int k=0;k<n;++k){
                if (i!=k){
                    if (k<i){
                        a[j-1][k]=arr[j][k];
                    }
                    else if (k>i){
                        a[j-1][k-1]=arr[j][k];
                    }
                }
            }
        }
        int exp=pow(-1,i);
        sum=sum + exp*(det(n-1,a))*arr[0][i];
    }
    return(sum);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for (int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&arr[i][j]);
        }
    }
    int p=det(n,arr);
    printf("Determinant is : %d \n",p);
}