#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        c=c/2;
        if (a<=c && a<=b){
            printf("%d \n",a);
        }
        else if (b<=c && b<=a){
            printf("%d \n",b);
        }
        else {
            printf("%d \n",c);
        }

    }
}