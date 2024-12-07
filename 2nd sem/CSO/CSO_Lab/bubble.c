#include <stdio.h>

long long int bubble(long long int *array ,long int N);

int main(){
    long long int n,b;
    scanf("%lld",&n);
    long long int array[n];
    for(long long int i=0;i<n;++i){
        scanf("%lld",&array[i]);
    }
    bubble(array,n);
    for(long long int i=0;i<n;++i){
        printf("%lld ",array[i]);
    }
    printf("\n");
}