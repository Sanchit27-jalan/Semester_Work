#include <stdio.h>

long long int answer(long long int* array,long long int *result,int n);

int main(){
    long long int n,b;
    scanf("%lld",&n);
    long long int array[n];
    for(long long int i=0;i<n;++i){
        scanf("%lld",&array[i]);
    }
    long long int result[n];
    answer(array,result,n);
    for(long long int i=0;i<n;++i){
        printf("%lld ",result[i]);
    }
    printf("\n");
}