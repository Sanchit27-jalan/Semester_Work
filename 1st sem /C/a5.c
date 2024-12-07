#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int t,i,n,m,r,c,flag,d=0,i1=0,j1=0,e=0,f,sum;
    scanf("%d",&t);
    for (i=0;i<t;++i){
        scanf("%d %d %d %d",&n,&m,&r,&c);
        int arr[n][m];
        for (int j=0;j<n;++j){
            for (int k=0;k<m;++k){
                scanf("%d",&arr[j][k]);
            }
        }
        int min=10000000;
        flag=0;
        sum=0;
        for (int j=0;j<n;++j){
            for (int k=0;k<m;++k){
                if (arr[j][k]==1){
                    f= abs(r-(j+1)) + abs(c-(k+1));
                    if (f<min){
                        min=f;
                        flag=0;
                        d=(j+1);
                        e=(k+1);
                        sum=sum+1;
                    }
                    else if(min==f){
                        flag=1;
                        sum=sum+1;
                    }
                    }
                }
        }
        int u=0;
        for (int j=0;j<n;++j){
            for (int k=0;k<m;++k){
                if (arr[j][k]==1){
                    f= abs(r-(j+1)) + abs(c-(k+1));
                    if (f==min){
                        i1=(j+1);
                        j1=(k+1);
                        u=1;
                        break;
                    }
                }
            }
            if (u==1){
                break;
                }
            }
        if (sum==0){
            printf("%d \n",-1);
        }

        else if (flag==0){
            printf("%d %d \n",d,e);
        }
        else if (flag==1){
            printf("%d %d \n",i1,j1);
        }
    }
}