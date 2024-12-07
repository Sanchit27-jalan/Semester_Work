#include <stdio.h>
#include<string.h>
char arr1[40320][9];
int count=0;
int power(int x,int y){
    int product=1;
    for (int i=0;i<y;++i){
        product=product*x;
    }
    return product;
}
int fact(int n){
    if (n==1){
        return 1;
    }
    else {
        return(n*fact(n-1));
    }
}
void swapping(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
    return;
}
void perm(char arr2[], int start, int end,int arr[])
{
    if (start == (end - 1))
    {
        strcpy(arr1[count],arr2);
        count=count+1;
    }
    for (int i = start; i < end; ++i)
    {
        swapping(&arr2[start], &arr2[i]);
        perm(arr2, start + 1, end,arr);
        swapping(&arr2[start], &arr2[i]);
    }
}
static int comp(const void *a,const void *b){
    return strcmp((const char *)a, (const char *)b);
}
int main(){
    char arr2[8];
    scanf("%s",arr2);
    int n=0;
    for(int i=0;arr2[i] != '\0'; ++i){
            n=n+1;
    }
    int arr[fact(n)];
    for (int i=0;i<40320;++i){
        for(int j=0;j<9;++j){
            arr1[i][j]='\0';
        }
    }
    for (int i=0;i<fact(n);++i){
        arr[i]=-1;
    }
    perm(arr2,0,n,arr);
    qsort(arr1,count,sizeof(arr1[0]),comp);
    char arr4[40320][9];
    int c=0;
    for(int i=0;i<fact(n);++i){
        int sum=0;
        int flag=0;
        for(int j=0;j<n;++j){
            int y=arr1[i][j]-90;
            sum=sum+power(10,j)*y;
        }
        int index=0;
        for(int k=0;k<=c;++k){
            if (sum==arr[k]){
                flag=1;
                break;
            }
            else if(arr[k]==-1){
                index=k;
                break;
            }
        }
        if (flag==0){
            arr[index]=sum;
            strcpy(arr4[c],arr1[i]);
            c++;
        }
    }
    printf("%d \n",c);
    for(int i=0;i<fact(n);++i){
        if (arr[i]==-1){
            break;
        }
        else{
            printf("%s \n",arr4[i]);
        }
    }
}
