#include <stdio.h>
int main(){
    printf("Enter year");
    int b;
    scanf("%d",&b);
    if (b%400==0){
        printf("%d is a leap year",b);}
    else if(b%100==0){
        printf("%d is not a leap year",b);
    }
    else if(b%4==0){
        printf("%d is a leap year",b);
    }
    else{
        printf("%d is not a leap year",b);
    }
}