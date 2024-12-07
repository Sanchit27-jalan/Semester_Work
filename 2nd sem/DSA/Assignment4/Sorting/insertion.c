#include <stdio.h>

void insertionsort(int* arr,int n){
    for(int i=1;i<n;++i){
        int curr=arr[i];
        int j;
        for(j=i-1;j>=0;--j){
            if(arr[j]>curr){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j]=curr;
    }
}

int main(){
    int arr[10]={10,9,8,7,6,11,4,3,2,1};
    insertionsort(arr,10);
    for(int i=0;i<10;++i){
        printf("%d ",arr[i]);
    }
}