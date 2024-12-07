#include <stdio.h>
#include<string.h>
void merge(char *L,char *R,char *arr1,int sL,int sR){
    int l=0,r=0,c=0;
    while (c<sL+sR){
        if(l==sL){
            strcpy(arr1[c++],R[r++]);
        }
        else if(r==sR){
            strcpy(arr1[c++],L[l++]);
        }
        else if (strcmp(L[l],R[r])>0){
            strcpy(arr1[c++],R[r++]);
        }
        else{
            strcpy(arr1[c++],L[l++]);
        }
    }
}
void sorting(int arr[][4],int len){
    if (len==1){ 
        return;
    }
    else{
        int mid=len/2;
        int L[mid][4];
        for(int i=0;i<mid;++i){
            strcpy(L[i],arr[i]);
        }
        int R[len-mid][4];
        for(int j=mid;j<len;++j){
            strcpy(R[j-mid],arr[j]);
        }
        sorting(L,mid);
        sorting(R,len-mid);
        merge(L,R,arr,mid,(len-mid));
    }
}
int main(){
    char arr1[3][4]={"gfgs","abcd","vcas"};
    sorting(arr1[3][4],3);
    for (int i=0;i<3;++i){
        printf("%s \n",arr1[i]);
    }
}