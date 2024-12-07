#include <stdio.h>
void seq(int n){
    if (n==1){
        printf("1 ");
    }
    else{
        seq(n-1);
        printf("%d ",n);
        seq(n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    seq(n);
}