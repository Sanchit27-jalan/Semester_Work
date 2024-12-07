#include <stdio.h>
int main(){
    int t,n,k,j,b;
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        scanf("%d %d",&n,&b);
        int yr=0,yl=0,xu=0,xd=0;
        for (int l=0;l<n;++l){
            scanf("%d %d",&j,&k);
            if (j>0){
                yr=yr+1;
            }
            else if(j<0){
                yl=yl+1;
            }
            if(k>0){
                xu=xu+1;
            }
            else if(k<0){
                xd=xd+1;
            }
        }
        if (yr<=b || yl<=b || xu<=b || xd<=b){
                printf("YES\n");
            }
        else{
                printf("NO\n");
            }
    }
}