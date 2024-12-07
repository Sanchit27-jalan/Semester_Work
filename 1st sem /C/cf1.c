#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    int sum1=0,sum2=0,sum3=0,sum4=0;
    for(int j=0;j<n;++j){
        if (arr[j]==1){
            sum1=sum1+1;
        }
        else if(arr[j]==2){
            sum2=sum2+1;
        }
        else if(arr[j]==3){
            sum3=sum3+1;
        }
        else{
            sum4=sum4+1;
        }
    }
    int sum=sum4;
    if(sum3>=sum1){
        sum=sum+sum3;
        sum1=0;
    }
    else{
        int d=sum1-sum3;
        sum=sum+d;
        sum1=sum1-sum3;
    }
    if(sum2%2==0){
        sum=sum+sum2/2;
    }
    else{
        sum=sum+sum2/2;
        sum2=1;
    }
    if(sum2==1 && sum1>=2){
        sum=sum+1;
        sum1=sum1-2;
    }
    else if(sum2==1 && sum1>=1){
        sum=sum+1;
        sum1=0;
    }
    else if(sum2==1 && sum1==0){
        sum=sum+1;
    }
    if (sum1!=0){
        int a=sum1%4;
        int b=sum1/4;
        sum=sum+a+b;
    }
    printf("%d",sum);
}