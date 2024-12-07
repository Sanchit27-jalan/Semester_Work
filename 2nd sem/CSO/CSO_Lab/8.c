#include <stdio.h>

void sort(long long int* array,int n);

int main(){
    long long int n,b;
    scanf("%lld",&n);
    long long int array[n];
    for(long long int i=0;i<n;++i){
        scanf("%lld",&array[i]);
    }
    sort(array,n);
    for(long long int i=0;i<n;++i){
        printf("%lld ",array[i]);
    }
    printf("\n");
}