#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for (int k=0;k<t;++k){
        int a,n;
    scanf("%d %d",&a,&n);
    int arr[n];
    for (int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for (int j=0;j<n;++j){
        int p=a/arr[n-j-1];
        sum=sum+p;
        a=a%arr[n-j-1];
    }
    printf("%d \n",sum);
    }
}
