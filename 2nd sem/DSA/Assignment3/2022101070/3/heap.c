#include "heap.h"


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