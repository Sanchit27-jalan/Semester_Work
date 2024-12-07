#include "heap.h"

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    heap h = create(n+1);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        insert(h, arr[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        extracting_max_to_last(h);
    }
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == h->elements[i + 1] && i!=(n-1))
        {
            int temp = h->elements[i+1];
            h->elements[i+1] = h->elements[i+2];
            h->elements[i+2] = temp;
        }
        if(arr[i] == h->elements[i + 1] && i==(n-1)){
            int temp = h->elements[i+1];
            h->elements[i+1] = h->elements[i];
            h->elements[i] = temp;
        }
        
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", h->elements[i]);
    }
    printf("\n");
}