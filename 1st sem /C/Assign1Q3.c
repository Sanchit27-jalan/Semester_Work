#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter largest number");
    scanf("%d",&a);
    printf("Enter second number");
    scanf("%d",&b);
    printf("Enter third number");
    scanf("%d",&c);
    if (a*a==(b*b +c*c)){
        printf("The numbers form a pythagorean triplet");
        }
    else{
        printf("The numbers do not form a pythagorean triplet");
    }
    return 0;
}
