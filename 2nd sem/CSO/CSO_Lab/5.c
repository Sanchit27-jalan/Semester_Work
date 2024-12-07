#include <stdio.h>

void convert(long long int n,long long int* given,long long int* result);

int main(){
    long long int n;
    scanf("%lld",&n);
    long long int given[n];
    for(long long int i=0;i<n;++i){
        scanf("%lld",&given[i]);
    }
    long long int result[n];
    convert(n,given,result);
    for(long long int i=0;i<n;++i){
        printf("%lld ",result[i]);
    }
    printf("\n");
}