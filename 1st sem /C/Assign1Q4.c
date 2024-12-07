#include<stdio.h>
int main(){
    printf("enter number");
    int a,b,c,d;
    scanf("%d",&a);
    int i,j;
    c=0;
    for (i=4;i>=1;--i){
        b=a%10;
        d=1;
        for (j=1;j<i;++j){
            d=d*10;
        }
        a=a/10;
        c=c+(b*d);
    }
    printf("The number in reverse is: %d",c);
    return 0;
}