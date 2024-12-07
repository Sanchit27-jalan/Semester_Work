#include <stdio.h>
void filling(int n,char arr[]){
    int sum=0,plus_ct=0;
    for(int i=0;i<2*n;++i){
        if (arr[i]==0){
            break;
        }
        if(arr[i]=='+'){
            sum=sum+1;
            plus_ct=plus_ct+1;
        }
        else{
            sum=sum-1;
        }
        if (sum<0){
            return;
        }
    }
    if(plus_ct>n){
        return;
    }
    char arr1[2*n];
    char arr2[2*n];
    int index=0;
    for (int i=0;i<2*n;++i){
        arr1[i]='\0';
        arr2[i]='\0';
    }
    for(int i=0;i<2*n;++i){
        if (arr[i]==0){
            index=i;
            break;
        }
        else{
        arr1[i]=arr[i];
        arr2[i]=arr[i];
        index=i;
        }
    }
    if(index==(2*n-1)){
        arr1[index]='-';
        //printf("%s \n",arr1);
        for(int i = 0; i < 2*n; i++){
            printf("%c", arr1[i]);
        }
        printf("\n");
    }
    else{
        arr1[index]='+';
        arr2[index]='-';
        filling(n,arr1);
        filling(n,arr2);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    char arr[2*n];
    for (int i=0;i<2*n;++i){
        arr[i]='\0';
    }
    arr[0]='+';
    if(n==1){
        char arr1[2]={'+','-'};
        //printf("%s \n",arr1);
        for(int i = 0; i < 2*n; i++){
            printf("%c", arr1[i]);
        }
        printf("\n");
    }
    else{
        filling(n,arr);
    }
}