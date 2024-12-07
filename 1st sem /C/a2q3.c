#include <stdio.h>
#include <stdlib.h>
int count=0;
int arr[100][8];
int arr1[8];
int checking(int j,int k,int i,int t){
    if(abs(k-j)==abs(t-i)){
        return 1;
    }
    else{
        return 0;
    }
}
int place(int k,int i){
    for(int j=0;j<k-1;++j){
        int p=0;
        p=checking(k-1,j,i,arr1[j]);
        if(arr1[j]==i || p ){
            return 0;
        }
    }
    return 1;
}
void nqueens(int k,int n){
    for(int i=0;i<n;++i){
        int p=place(k,i);
        if(p==1){
            arr1[k-1]=i;
            if(k==n){
                for(int t=0;t<8;++t){
                    arr[count][t]=arr1[t];
                }
                count++;
            }
            else{
                nqueens(k+1,n);
            }
        }
    }
}
int main(){
    for (int i=0;i<100;++i){
        for(int j=0;j<8;++j){
            arr[i][j]=0;
        }
    }
    for (int i=0;i<8;++i){
        arr1[i]=0;
    }
    nqueens(1,8);
    char arr2[8][9];
    for (int i=0;i<8;++i){
        scanf("%s",arr2[i]);
    }
    int c=0;
    for(int i=0;i<92;++i){
        int flag=1;
        for(int j=0;j<8;++j){
            int p=arr[i][j];
            if (arr2[j][p]=='*'){
                flag=0;
                break;
            }

        }
        if(flag==1){
            c++;
        }
    }
    printf("%d ",c);
}