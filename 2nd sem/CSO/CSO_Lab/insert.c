#include <stdio.h>

long long int insert(long long int *array ,long int N);

int main(){
    long long int n,b;
    scanf("%lld",&n);
    long long int array[n];
    for(long long int i=0;i<n;++i){
        scanf("%lld",&array[i]);
    }
    insert(array,n);
    for(long long int i=0;i<n;++i){
        printf("%lld ",array[i]);
    }
    printf("\n");
}