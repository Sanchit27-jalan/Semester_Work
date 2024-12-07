#include "sort.h"

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

int changing_max_element(heap h)
{
    int n = h->elements[1];
    h->elements[1]--;
    int i = 1;
    while (i * 2 <= h->size)
    {
        int j = 2 * i;
        if ((j + 1) > h->size)
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
        else if ((j + 1) <= h->size)
        {
            if (h->elements[j] >= h->elements[j + 1] && h->elements[i] < h->elements[j])
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
    return n;
}


long long int happy_calc(heap h,int k){
    long long int ans=0;
    for(int i=0;i<k;++i){
        int k=changing_max_element(h);
        if(k<=0){
            break;
        }
        else{
            ans=ans+k;
        }
    }
    return ans;
}