#include <stdio.h>

long long int calc(long long int* array,int n);

int main(){
    long long int n,b;
    scanf("%lld",&n);
    long long int array[n];
    for(long long int i=0;i<n;++i){
        scanf("%lld",&array[i]);
    }
    long long int ans=calc(array,n);
    printf("%lld\n",ans);
}