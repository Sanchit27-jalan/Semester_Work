#include <stdio.h>


int median(int *arr,int l,int u){
    int e1=arr[l];
    int e2=arr[u];
    int e3=arr[(l+u)/2];
    if(e2>=e1 && e2<=e3){
        return u;
    }
    else if(e2>=e3 && e2<=e1){
        return u;
    }
    else if(e1>=e2 && e1<=e3){
        return l;
    }
    else if(e1<=e2 && e1>=e3){
        return l;
    }
    else{
        return (l+u)/2;
    }
}

int partition(int *arr,int l,int u,int pivot_index){
    int pivot_value=arr[pivot_index];
    int i=l;
    int j=u;
    while(j>i){
        while(arr[i]<pivot_value){
            i++;
        }
        while(arr[j]>pivot_value){
            j--;
        }
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    arr[j]=pivot_value;
    return j;
}
void qsortd(int *arr,int l,int u){
    if(u>l){
        int pivot_index=median(arr,l,u);
        int sorted_index=partition(arr,l,u,pivot_index);
        qsortd(arr,l,sorted_index-1);
        qsortd(arr,sorted_index+1,u);
    }
    return;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsortd(arr,0,n-1);
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}