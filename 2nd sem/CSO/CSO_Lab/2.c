#include <stdio.h>

void conversion(long long int n,long long int* array);

int main(){
    long long int n; 
    scanf("%lld", &n);
    long long int array[n];
    conversion(n,array);
    for (long long int i = 0; i < n; i++)
    {
        printf("%lld ", array[i]);
    }

    printf("\n");

    return 0;
}