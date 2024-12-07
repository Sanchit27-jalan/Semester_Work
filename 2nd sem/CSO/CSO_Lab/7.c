#include <stdio.h>

long long int maxsum(long long int* x,long long int length,long long int number);

int main(){
    long long int n,b;
    scanf("%lld %lld",&n,&b);
    long long int array[n];
    for(long long int i=0;i<n;++i){
        scanf("%lld",&array[i]);
    }
    long long int ans=maxsum(array,n,b);
    printf("Max Sum is : %lld \n",ans);
}
