#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int l,int mid,int r){
    int t=r-l+1;
    int *new=malloc(sizeof(int)*t);
    int j=0;
    int leftsize=mid-l+1;
    int rightsize=r-mid;
    int leftfilled=0;
    int leftindex=l;
    int rightfilled=0;
    int rightindex=mid+1;
    while(j<t){
        if(leftfilled==leftsize){
            new[j]=arr[rightindex];
            j++;
            rightfilled++;
            rightindex++;
        }
        else if(rightfilled==rightsize){
            new[j]=arr[leftindex];
            j++;
            leftfilled++;
            leftindex++;
        }
        else{
            if(arr[leftindex]<arr[rightindex]){
                new[j]=arr[leftindex];
                j++;
                leftfilled++;
                leftindex++;
            }
            else{
                new[j]=arr[rightindex];
                j++;
                rightfilled++;
                rightindex++;
            }
        }
    }
    for(int i=0;i<t;++i){
        arr[l+i]=new[i];
    }
    free(new);
    return;
}
void mergesortd(int *arr,int l,int r){
    if(l>=r){
        return;
    }
    else{
        int mid=(l+r)/2;
        mergesortd(arr,l,mid);
        mergesortd(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesortd(arr,0,n-1);
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}