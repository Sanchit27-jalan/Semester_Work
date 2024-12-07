#include <stdio.h>

// void bubblesort(int* arr,int n){
//     for(int i=1;i<n;++i){
//         int curr=arr[i];
//         int j=i-1;
//         while(j>=0){
//             if(arr[j]>curr){
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//                 j--;
//             }
//             else{
//                 break;
//             }
//         }

//     }
// }

void bubblesort(int* arr,int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j+1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    bubblesort(arr,10);
    for(int i=0;i<10;++i){
        printf("%d ",arr[i]);
    }
}