#include<stdio.h>
int main(){
    int n1,n2,n3,i;
    n1=n2=-99999;
    for (i=1;i<7;++i){
        printf("Enter number");
        scanf("%d",&n3);
        if (n3>n1){
            n2=n1;
            n1=n3;}
        else if(n3>n2){
            n2=n3;}
    }
    printf("Second largest number is %d",n2);
}