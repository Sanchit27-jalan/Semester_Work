#include<stdio.h>
#include<stdlib.h>


void answer(int n,int k,long long int arr1[n],long long int arr2[k],int x,int y)
{
    //printf("%d \n",1);

    int i,j;

    if(x==k)
    {
        for(j=0;j<k;j++)
        {
            printf("%lld ",arr2[j]);
        }
        printf("\n");
        return;
       }
    
    
    for(i=y;i<=n-k+x;i++)
    {
        arr2[x]=arr1[i];
        answer(n,k,arr1,arr2,x+1,i+1);    
    }
    

}



int main()
{
    int i,j,n,k;
    scanf("%d %d",&n,&k);
    long long int arr[n];
    long long int final[k];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    if(n==k)
    {
        for(j=0;j<n;j++)
        {
            printf("%lld ",arr[j]);
        }
        printf("\n");
    }
    else
    {
    answer(n,k,arr,final,0,0);
    }


    return 0;
}