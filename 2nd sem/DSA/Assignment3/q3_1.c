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
    for (int i = 1; i < cap; ++i)
    {
        h->elements[i] = 0;
    }
    h->elements[0] = -10000000;
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
        int i=t+1;
        while (i>1){
            int j=i/2;
            if(h->elements[i]>=h->elements[j]){
                break;
            }
            else{
                int temp=h->elements[i];
                h->elements[i]=h->elements[j];
                h->elements[j]=temp;
            }
            i=j;
        }
        h->size++;
    }
    return;
}

int deleting_min_element(heap h)
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
            if (h->elements[i] <= h->elements[j])
            {
                break;
            }
            else
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }
        }
        else if ((j + 1) < h->size)
        {
            if (h->elements[j] <= h->elements[j + 1] && h->elements[i] > h->elements[j])
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }
            else if (h->elements[j + 1] < h->elements[j] && h->elements[i] > h->elements[j + 1])
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[j + 1];
                h->elements[j + 1] = temp;
                i = j + 1;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    h->size--;
    return n;
}

int main()
{
    int n;
    scanf("%d", &n);
    int minus_ct_before_first_positive = 0;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] >= 0)
        {
            break;
        }
        else
        {
            minus_ct_before_first_positive++;
        }
    }
    int ct = 0;
    long long int sum = 0;
    heap h = create(n + 1);
    for (int i = minus_ct_before_first_positive; i < n; i++)
    {
        if (arr[i] < 0)
        {
            insert(h, arr[i]);
        }
        sum = sum + arr[i];
        ct++;
        if (sum < 0)
        {
            long long int t = deleting_min_element(h);
            sum = sum - t;
            ct--;
        }
    }
    printf("%d\n", ct);
}
