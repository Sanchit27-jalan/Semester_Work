#include <stdio.h>
int coin(int n,int arr1[n]){
    /*if (arr[n]!=-1){
        return(arr[n]);
    }*/
    if(n==0){
         return("%d",0);
    }
    else if(n<0){
        return(10000);
    }
    else{
        int min=1000000;
        for (int m=0;m<n;++m){
            if (coin(n-arr1[m],arr1[n])<min){
                min=coin(n-arr1[m],arr1[n]);
            }
        }
        //arr[n]=min;
        return(min+1);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        int a,n;
        scanf("%d %d",&a,&n);
        int arr1[n];
        for(int k=0;k<n;++k){
            scanf("%d",&arr1[k]);
        }
        printf("%d",arr1[n-1]);
        int p=coin(a,arr1[n]);
        if (p>1000){
            printf("%d",-1);
        }
        else{
            printf("%d",p);
        }
    }
}