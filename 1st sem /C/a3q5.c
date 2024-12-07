#include <stdio.h>
void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
void permutate(char arr,int n,int start,int end){
    if(start==(end-1)){
        printf("%s",arr);
    }
    for (int i=0;i<n-1;++i){
        swap(&arr[n-1-i],&arr[n]);
        permutate(arr,n,start+1,end);
        swap(&arr[n-1-i],&arr[n]);
    }
}
int main(){
    int n ;
    scanf("%d",&n);
    char arr[2*n+1];
    for (int i=0 ;i<n;++i){
        arr[i]='+';
        arr[n+i]='-';
    }
    arr[2*n]='\0';
}
