#include <stdio.h>

void selectionsort(int* arr,int n){
    for(int i=0;i<n;++i){
        int index;
        int min=1e9;
        for(int j=i+1;j<n;++j){
            if(arr[j]<min){
                index=j;
                min=arr[j];
            }
        }
        if(arr[i]>arr[index]){
            int temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
        }
    }
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,6,9,10};
    selectionsort(arr,10);
    for(int i=0;i<10;++i){
        printf("%d ",arr[i]);
    }
}