#include<stdio.h>
int main(){
    int a,i;
    printf("Enter the number:");
    scanf("%d",&a);
    int n=a&1;
    a=a>>1;
    int b=a&1;
    a=a>>1;
    int c=a&1;
    printf("Least 3 significant bits are:%d,%d,%d",c,b,n);
    return 0;

}