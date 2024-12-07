#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        int n,m,ind=0;
        scanf("%d %d",&n,&m);
        int arr[n];
        for (int j=0;j<n;++j){
            scanf("%d",&arr[j]);
        }
        int arr1[m];
        for (int y=0;y<m;++y){
            arr1[y]=0;
        }
        for (int k=0;k<n;++k){
            int c= arr[k];
            arr1[c-1]=arr1[c-1]+1;
        }
        int max=-999;
        int flag=1;
        for (int l=0;l<m;++l){
            if (arr1[l]>max){
                max=arr1[l];
                ind=(l+1);
            }
        }
        for (int b=0;b<m;++b){
            if (arr1[b]==max){
                if (b!=(ind-1)){
                    flag=0;
                    break;
                }
            }
        }
        if (flag==0){
            printf("%d \n",-1);
        }
        else{
            printf("%d \n",ind);
        }
    }
}