#include <stdio.h>

long long int gcd(long long int a,long long int b);

int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    long long int ans=gcd(a,b);
    printf("%lld \n",ans);
}