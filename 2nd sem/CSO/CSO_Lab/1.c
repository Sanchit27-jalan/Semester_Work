#include <stdio.h>

long long int bacteria(long long int x);

int main(){
    long long int x;
    scanf("%lld",&x);
    long long int ans=bacteria(x);
    printf("No of minimum are: %lld \n",ans);
}