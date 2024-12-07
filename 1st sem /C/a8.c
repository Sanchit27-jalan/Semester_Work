#include <stdio.h>
int main(){
    int t,a,n,c,e,f;
    int index,flag;
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        scanf("%d %d %d",&a,&n,&c);
        int d=a/n;
        if (d>0){
            e= a%n;
        }
        else if(d==0){
            e=a;
        }
        flag=0;
        for (int j=0;j<n;++j){
            f=(10*e)/n;
            e=(10*e)%n;
            if (f==c){
                flag=1;
                index=(j+1);
                break;
            }
        }
        if (flag==0){
            printf("%d \n",-1);}
        else if (flag==1){
            printf("%d \n",index);
    }
    }
    }