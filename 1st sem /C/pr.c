#include <stdio.h>
void swapping(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}
void perm(int arr[],int start,int end){
    if(start==(end-1)){
        for (int i=0;i<end;++i){
            printf("%d",arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i=start;i<end;++i){
        swapping(&arr[start],&arr[i]);
        perm(arr,start+1,end);
        swapping(&arr[start],&arr[i]);
    }
}
int main(){
    int arr1[3]={1,2,3};
    perm(arr1,0,3);
}