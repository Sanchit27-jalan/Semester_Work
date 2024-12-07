#include <stdio.h>
int fun(int n){
    return(n*n+2*n+3);
}
int main(){
    int t;
    scanf("%d",&t);
    int p= fun(fun(fun(t)+t)+fun(fun(t)));
    printf("%d",p);
}