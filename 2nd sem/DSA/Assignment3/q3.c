#include <stdio.h>
#include <stdlib.h>
struct minus
{
    int value;
    int index;
};
struct stheap
{
    int size;
    int capacity;
    struct minus *elements;
};

typedef struct stheap *heap;
heap create(int cap)
{
    heap h;
    h = malloc(sizeof(struct stheap));
    h->size = 0;
    h->capacity = cap;
    h->elements = (struct minus *)malloc(sizeof(struct minus) * cap);
    return h;
}
int compare(struct minus a, struct minus b)
{
    if (a.value == b.value)
    {
        return a.index < b.index;
    }
    return a.value > b.value;
}
void insert(heap h, struct minus n)
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
            if (h->elements[i].value <= h->elements[i / 2].value)
            {
                break;
            }
            else
            {
                struct minus temp = h->elements[i];
                h->elements[i] = h->elements[i / 2];
                h->elements[i / 2] = temp;
            }
        }
        h->size++;
    }
    return;
}

struct minus delete(heap h)
{
    struct minus n = h->elements[1];
    struct minus x = h->elements[h->size];
    h->elements[1] = x;
    h->elements[h->size] = n;
    int i = 1;
    while (i * 2 < h->size)
    {
        int j = 2 * i;
        if ((j + 1) == h->size)
        {
            if (h->elements[i].value >= h->elements[j].value)
            {
                break;
            }
            else
            {
                struct minus temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }

        }
        else if ((j + 1) < h->size)
        {
            if (h->elements[j].value > h->elements[j + 1].value && h->elements[i].value < h->elements[j].value)
            {
                struct minus temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }
            else if (h->elements[j + 1].value > h->elements[j].value && h->elements[i].value < h->elements[j + 1].value)
            {
                struct minus temp = h->elements[i];
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
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    heap h = create(n);

    int minus_ct = 0;
    int sum[n];
    for (int i = 0; i < n; ++i)
    {
        sum[i] = 0;
    }
    if (arr[0] >= 0)
    {
        sum[0] = arr[0];
    }
    else
    {
        sum[0] = 0;
        minus_ct++;
        struct minus new;
        new.index = 0;
        new.value = arr[0];
        insert(h, new);
    }
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < 0)
        {
            minus_ct++;
            struct minus new;
            new.index = i;
            new.value = arr[i];
            insert(h, new);
            sum[i] = sum[i - 1];
        }
        if (arr[i] >= 0)
        {
            sum[i] = sum[i - 1] + arr[i];
        }
    }
    for (int i = 0; i < minus_ct; ++i)
    {
        printf("%d %d\n", h->elements[i + 1].index, h->elements[i + 1].value);
    }
    int count = 0;
    for (int i = 0; i < minus_ct; ++i)
    {
        struct minus del = delete (h);
        int in = del.index;
        // printf("%d %d\n",del.value,del.index);
        int flag = 0;
        for (int j = in; j < n; ++j)
        {
            if (sum[j] + del.value < 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (int j = in; j < n; ++j)
            {
                sum[j] = sum[j] + del.value;
            }
            count++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] >= 0)
        {
            count++;
        }
    }
    printf("%d\n", count);
}