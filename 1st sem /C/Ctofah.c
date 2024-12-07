#include <stdio.h>
int main(){
    printf("Enter temperature in celcius");
    int a,b;
    scanf("%d",&a);
    b=1.8*a + 32;
    printf("Temperature in faherneit is: %d \n",b);
    return 0;
}