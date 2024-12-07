#include <stdio.h>
#include <stdlib.h>

struct elements
{
    int a1;
    int b1;
};
void merge(struct elements *arr, int l, int mid, int r)
{
    int t = r - l + 1;
    struct elements *new = malloc(sizeof(struct elements) * t);
    int j = 0;
    int leftsize = mid - l + 1;
    int rightsize = r - mid;
    int leftfilled = 0;
    int leftindex = l;
    int rightfilled = 0;
    int rightindex = mid + 1;
    while (j < t)
    {
        if (leftfilled == leftsize)
        {
            new[j] = arr[rightindex];
            j++;
            rightfilled++;
            rightindex++;
        }
        else if (rightfilled == rightsize)
        {
            new[j] = arr[leftindex];
            j++;
            leftfilled++;
            leftindex++;
        }
        else
        {
            if (arr[leftindex].a1 < arr[rightindex].a1)
            {
                new[j] = arr[leftindex];
                j++;
                leftfilled++;
                leftindex++;
            }
            else if(arr[leftindex].a1 > arr[rightindex].a1)
            {
                new[j] = arr[rightindex];
                j++;
                rightfilled++;
                rightindex++;
            }
            else{
                if(arr[leftindex].b1<arr[rightindex].b1){
                    new[j] = arr[leftindex];
                    j++;
                    leftfilled++;
                    leftindex++;
                }
                else{
                    new[j] = arr[rightindex];
                    j++;
                    rightfilled++;
                    rightindex++;
                }
            }
            // else{
            //     new[j] = arr[rightindex];
            //     j++;
            //     rightfilled++;
            //     rightindex++;
            // }
        }
    }
    for (int i = 0; i < t; ++i)
    {
        arr[l + i] = new[i];
    }
    free(new);
    return;
}
void mergesortd(struct elements *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        mergesortd(arr, l, mid);
        mergesortd(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int *journaltwocalc(int*a,int*b,int n){
    int *c = malloc(sizeof(int) * n);
        int min = a[0];
        if (min > b[0])
        {
            min = b[0];
        }
        c[0] = min;
        // for(int i=0;i<n;++i){
        //     printf("%d ",a[i]);
        // }
        // printf("\n");
        for (int i = 1; i < n; ++i)
        {
            // int min = a[i];
            // if (min > b[i])
            // {
            //     min = b[i];
            // }
            // if(min>c[i-1]){
            //     c[i] = min;
            // }
            // c[i] = min;
            if(a[i]>b[i]){
                if(b[i]>=c[i-1]){
                    c[i]=b[i];
                    // printf("%d\n",b[i]);
                    // printf("wtf1\n");
                }
                else{
                    c[i]=a[i];
                    // printf("%d \n",a[i]);
                    // printf("wtf2\n");
                }
            }
            else{
                // if(a[i]>c[i-1]){
                //     c[i]=a[i];
                // }
                // else{
                //     c[i]=b[i];
                // }
                c[i]=a[i];
                // printf("%d \n",a[i]);
                // printf("wtf3\n");
            }
        }
        return c;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        int n;
        scanf("%d", &n);
        int *a = malloc(sizeof(int) * n);
        int *b = malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &b[i]);
        }
        struct elements *elem = malloc(sizeof(struct elements) * n);
        for (int i = 0; i < n; ++i)
        {
            elem[i].a1 = a[i];
            elem[i].b1 = b[i];
        }
        mergesortd(elem, 0, n - 1);
        // for(int i=0;i<n;++i){
        //     printf("%d %d\n",elem[i].a1,elem[i].b1);
        // }
        for (int i = 0; i < n; ++i)
        {
            a[i] = elem[i].a1;
            b[i] = elem[i].b1;
        }
        // for(int i=0;i<n;++i){
        //     printf("%d %d ")
        // }
        int *c=journaltwocalc(a,b,n);
        printf("%d %d\n", a[n - 1], c[n - 1]);
        free(c);
        free(b);
        free(a);
    }
}