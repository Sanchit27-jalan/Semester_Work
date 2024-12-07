#include <stdio.h>

long long int exists(long long int* x,long long int length,long long int number);

int main(){
    long long int n,b;
    scanf("%lld %lld",&n,&b);
    long long int array[2*n];
    for(long long int i=0;i<2*n;++i){
        scanf("%lld",&array[i]);
    }
    long long int ans=exists(array,n,b);
    // for(long long int i=0;i<2*n;++i){
    //     printf("%lld ",array[i]);
    // }
    // printf("\n");
    if(ans==1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
