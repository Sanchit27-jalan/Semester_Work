#include <stdio.h>

int palindrome(long long int n);

int main(){
    long long int n;
    scanf("%lld",&n);
    int x=palindrome(n);
    if(x==1){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}