#include <stdio.h>

int func(int n){
    if (n==0){
        return(0);
    }
    else if ( n>=1 && n<=9){
        return(1);
    }
    int temp=n;
    int max=n%10;
    n=n/10;
    for(int i=0;i<5;++i){
        if (n>0){
        int a=n%10;
        n=n/10;
        if(a>max){
            max=a;
        }
        }
        else{
            break;
        }
    }
    int p=func(temp-max)+1;
    return(p);
}
int main(){
    int n;
    scanf("%d",&n);
    int sum=func(n);
    printf("%d \n",sum);
}