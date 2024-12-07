#include <stdio.h>
void merge(int *L,int R[],int A[], int sL, int sR){
    int l=0,r=0,c=0;
    while (c<sL+sR){
        if (l==sL){
            A[c]=R[r];
            c++;
            r++;
        }
        else if(r==sR){
            A[c]=L[l];
            c++;
            l++;
        }
        else if (L[l]>R[r]){
            A[c]=R[r];
            r++;
            c++;
        }
        else{
            A[c]=L[l];
            c++;
            l++;
        }
    }
}
void sorting(int arr[],int len){
    if (len==1){ 
        return;
    }
    else{
        int mid=len/2;
        int L[mid];
        for(int i=0;i<mid;++i){
            L[i]=arr[i];
        }
        int R[len-mid];
        for(int j=mid;j<len;++j){
            R[j-mid]=arr[j];
        }
        sorting(L,mid);
        sorting(R,len-mid);
        merge(L,R,arr,mid,(len-mid));
    }
}
int main(){
    int arr[8]={8,6,5,7,3,4,2,1};
    sorting(arr,7);
    for (int i=0;i<8;++i){
        printf("%d ",arr[i]);
    }
}