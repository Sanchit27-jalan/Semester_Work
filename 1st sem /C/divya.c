#include <stdio.h>
int main(){
    int n,a,b,c;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    int min;
    if(a<b && a<c){
        min=a;
        a=b;
        b=c;
    }
    else if(b<a && b<c){
        min=b;
        b=c;
    }
    else if (c<a && c<b){
        min=c;
    }
    int ct=0;
    int flag=0;
    while (n>0){
        if(min==1){
            printf("%d \n",n);
            flag=1;
            break;
        }
        else if((n-min)>=a || (n-min)>=b){
            n=n-min;
            ct=ct+1;
        }
        else if(n==a){
            n=n-a;
            ct=ct+1;
        }
        else if(n==b){
            n=n-b;
            ct=ct+1;
        }
    }
    if (flag==0){
        printf("%d \n",ct);
    }
}