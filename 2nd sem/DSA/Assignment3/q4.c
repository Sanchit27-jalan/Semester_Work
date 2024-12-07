#include <stdio.h>
#include <stdlib.h>

struct stheap
{
    int size;
    int capacity;
    int *elements;
};

typedef struct stheap *heap;
heap create(int cap)
{
    heap h;
    h = malloc(sizeof(struct stheap));
    h->size = 0;
    h->capacity = cap;
    h->elements = (int *)malloc(sizeof(int) * cap);
    return h;
}
void insert(heap h, int n)
{
    if (h->size == 0)
    {
        h->size++;
        h->elements[1] = n;
    }
    else
    {
        int t = h->size;
        h->elements[t + 1] = n;
        for (int i = t + 1; i > 1; i = i / 2)
        {
            if (h->elements[i] <= h->elements[i / 2])
            {
                break;
            }
            else
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[i / 2];
                h->elements[i / 2] = temp;
            }
        }
        h->size++;
    }
    return;
}

void extracting_max_to_last(heap h)
{
    int n = h->elements[1];
    int x = h->elements[h->size];
    h->elements[1] = x;
    h->elements[h->size] = n;
    int i = 1;
    while (i * 2 < h->size)
    {
        int j = 2 * i;
        if ((j + 1) == h->size)
        {
            if (h->elements[i] >= h->elements[j])
            {
                break;
            }
            else
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i=j;
            }
        }
        else if ((j + 1) < h->size)
        {
            if (h->elements[j] > h->elements[j + 1] && h->elements[i] < h->elements[j])
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i=j;
            }
            else if (h->elements[j + 1] > h->elements[j] && h->elements[i] < h->elements[j + 1])
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[j + 1];
                h->elements[j + 1] = temp;
                i=j+1;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    h->size--;
    return;
}
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