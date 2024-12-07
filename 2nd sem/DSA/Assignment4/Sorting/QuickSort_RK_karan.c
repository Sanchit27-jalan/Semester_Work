#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int medianof3(int *a, int l, int u)
{

    int mid = (l + u) / 2;
    if (a[l] > a[mid])
        swap(a, l, mid);
    if (a[l] > a[u])
        swap(a, l, u);
    if (a[mid] > a[u])
        swap(a, mid, u);
    swap(a, mid, u - 1);
    return a[u-1];
}

int QPartition(int *a, int l, int u, int pivt_val)
{
    int i = l;
    int j = u - 1;
    while (1)
    {
        while (a[++i] < pivt_val)
        {
        }
        while (a[--j] > pivt_val)
        {
        }
        if (i < j)
            swap(a, i, j);
        else
            break;
    }
    swap(a, i, u - 1);
    return i;
}

void QsortDriver(int *a, int l, int u,int k)
{
    if (l == u)
        return;
    else if (l == u - 1)
    {
        if (a[l] > a[u])
        {
            int temp = a[l];
            a[l] = a[u];
            a[u] = temp;
            return;
        }
        else
        {
            return;
        }
    }
    int pvt_val = medianof3(a, l, u);
    int pvt_index = QPartition(a, l, u, pvt_val);
    if(k-1>pvt_index){
        QsortDriver(a,pvt_index+1,u,k-pvt_index);
    }
    else if(k-1<pvt_index){
        QsortDriver(a, l, pvt_index - 1,k);
    }
    return;
}

void Qsort(int *a,int n,int k)
{
    QsortDriver(a,0,n-1,k);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Qsort(arr,n,3);
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    printf("%d \n",arr[2]);
}