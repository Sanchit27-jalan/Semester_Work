#include <stdio.h>
int main(){
    int i,t,n,j;
    scanf("%d",&t);
    for (i=0;i<t;++i){
        scanf("%d",&n);
        int arr[n];
        for (j=0;j<n;++j){
            scanf("%d",&arr[j]);
        }
        if (n%2!=0){
            printf("%d \n",-1);}
        else {
            int sum=0;
            for (int k=0;k<n;++k){
                sum=sum+arr[k];
            }
            if (sum>0){
                sum=sum/2;
                printf("%d \n",sum);}
            else if (sum==0){
                printf("%d \n",0);
            }
            else {
                sum=((-1)*sum)/2;
                printf("%d \n",sum);
            }
        }
    }
}