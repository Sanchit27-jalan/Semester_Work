#include <stdio.h>
#include <stdlib.h>

struct node
{
    int x;
    int y;
    int cost;
};
struct stheap
{
    int size;
    int capacity;
    struct node *elements;
};

typedef struct stheap *heap;
heap create(int cap)
{
    heap h;
    h = malloc(sizeof(struct stheap));
    h->size = 0;
    h->capacity = cap;
    h->elements = (struct node *)malloc(sizeof(struct node) * cap);
    return h;
}
void insert(heap h, struct node n)
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
            if (h->elements[i].cost > h->elements[i / 2].cost)
            {
                break;
            }
            else
            {
                struct node temp = h->elements[i];
                h->elements[i] = h->elements[i / 2];
                h->elements[i / 2] = temp;
            }
        }
        h->size++;
    }
    return;
}

struct node extracting_min_to_last(heap h)
{
    struct node n = h->elements[1];
    struct node x = h->elements[h->size];
    h->elements[1] = x;
    h->elements[h->size] = n;
    int i = 1;
    while (i * 2 < h->size)
    {
        int j = 2 * i;
        if ((j + 1) == h->size)
        {
            if (h->elements[i].cost <= h->elements[j].cost)
            {
                break;
            }
            else
            {
                struct node temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }
        }
        else if ((j + 1) < h->size)
        {
            if (h->elements[j].cost <= h->elements[j + 1].cost && h->elements[i].cost > h->elements[j].cost)
            {
                struct node temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }
            else if (h->elements[j + 1].cost < h->elements[j].cost && h->elements[i].cost > h->elements[j + 1].cost)
            {
                struct node temp = h->elements[i];
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

void leftchecker(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (y == 0)
    {
        return;
    }
    if (inheap[x][y - 1] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x][y - 1];
        cost[x][y - 1] = cost[x][y] + arr[x][y - 1];
        in.x = x;
        in.y = y - 1;
        insert(h, in);
        inheap[x][y - 1] = 1;
    }
    return;
}
void rightchecker(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (y == (m - 1))
    {
        return;
    }
    if (inheap[x][y + 1] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x][y + 1];
        cost[x][y + 1] = cost[x][y] + arr[x][y + 1];
        in.x = x;
        in.y = y + 1;
        insert(h, in);
        inheap[x][y + 1] = 1;
    }
    return;
}
void upchecker(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (x == 0)
    {
        return;
    }
    if (inheap[x - 1][y] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x - 1][y];
        cost[x - 1][y] = cost[x][y] + arr[x - 1][y];
        in.x = x - 1;
        in.y = y;
        insert(h, in);
        inheap[x - 1][y] = 1;
    }
    return;
}
void downchecker(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (x == (n - 1))
    {
        return;
    }
    if (inheap[x + 1][y] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x + 1][y];
        cost[x + 1][y] = cost[x][y] + arr[x + 1][y];
        in.x = x + 1;
        in.y = y;
        insert(h, in);
        inheap[x + 1][y] = 1;
    }
    return;
}
void upright(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (x == 0)
    {
        return;
    }
    if (y == (m - 1))
    {
        return;
    }
    if (inheap[x - 1][y + 1] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x - 1][y + 1];
        cost[x - 1][y + 1] = cost[x][y] + arr[x - 1][y + 1];
        in.x = x - 1;
        in.y = y + 1;
        insert(h, in);
        inheap[x - 1][y + 1] = 1;
    }
    return;
}
void upleft(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (x == 0)
    {
        return;
    }
    if (y == (0))
    {
        return;
    }
    if (inheap[x - 1][y - 1] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x - 1][y - 1];
        cost[x - 1][y - 1] = cost[x][y] + arr[x - 1][y - 1];
        in.x = x - 1;
        in.y = y - 1;
        insert(h, in);
        inheap[x - 1][y - 1] = 1;
    }
    return;
}
void downright(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (x == (n - 1))
    {
        return;
    }
    if (y == (m - 1))
    {
        return;
    }
    if (inheap[x + 1][y + 1] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x + 1][y + 1];
        cost[x + 1][y + 1] = cost[x][y] + arr[x + 1][y + 1];
        in.x = x + 1;
        in.y = y + 1;
        insert(h, in);
        inheap[x + 1][y + 1] = 1;
    }
    return;
}
void downleft(int **arr, int **cost, int n, int m, heap h, int **inheap, int x, int y)
{
    if (x == (n - 1))
    {
        return;
    }
    if (y == (0))
    {
        return;
    }
    if (inheap[x + 1][y - 1] == 0)
    {
        struct node in;
        in.cost = cost[x][y] + arr[x + 1][y - 1];
        cost[x + 1][y - 1] = cost[x][y] + arr[x + 1][y - 1];
        in.x = x + 1;
        in.y = y - 1;
        insert(h, in);
        inheap[x + 1][y - 1] = 1;
    }
    return;
}
int answerfind(int **arr, int **cost, int n, int m, heap h, int **inheap)
{
    // printf("Heap size : %d\n", h->size);
    struct node now = extracting_min_to_last(h);
    // for (int i = 1; i <= h->size; i++)
    // {
    //     printf("%d ", h->elements[i].cost);
    // }
    // printf("\n");
    while (now.x != (0) && now.y != (m - 1))
    {
        // printf("Dequeued nodes: %d %d %d\n", now.x, now.y, now.cost);
        // printf("Heap size : %d\n", h->size);
        leftchecker(arr, cost, n, m, h, inheap, now.x, now.y);
        rightchecker(arr, cost, n, m, h, inheap, now.x, now.y);
        upchecker(arr, cost, n, m, h, inheap, now.x, now.y);
        downchecker(arr, cost, n, m, h, inheap, now.x, now.y);
        upright(arr, cost, n, m, h, inheap, now.x, now.y);
        upleft(arr, cost, n, m, h, inheap, now.x, now.y);
        downleft(arr, cost, n, m, h, inheap, now.x, now.y);
        downright(arr, cost, n, m, h, inheap, now.x, now.y);
        now = extracting_min_to_last(h);
    }
    // printf("Dequeued nodes: %d %d %d\n", now.x, now.y, now.cost);
    return cost[now.x][now.y];
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        int m, n;
        scanf("%d %d", &n, &m);
        int **arr = malloc(sizeof(int *) * n);
        int **cost = malloc(sizeof(int *) * n);
        int **inheap = malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = malloc(sizeof(int) * m);
            cost[i] = malloc(sizeof(int) * m);
            inheap[i] = malloc(sizeof(int) * m);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &arr[i][j]);
                inheap[i][j] = 0;
            }
        }
        heap h = create(n * m + 10);
        for (int i = 0; i < n; i++)
        {
            struct node inserty;
            inserty.cost = arr[i][0];
            cost[i][0] = arr[i][0];
            inserty.x = i;
            inserty.y = 0;
            insert(h, inserty);
            inheap[i][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            struct node inserty;
            inserty.cost = arr[n - 1][i];
            cost[n - 1][i] = arr[n - 1][i];
            inserty.x = n - 1;
            inserty.y = i;
            insert(h, inserty);
            inheap[n - 1][i] = 1;
        }
        // for (int i = 1; i <= h->size; i++)
        // {
        //     printf("%d ", h->elements[i].cost);
        // }
        // printf("\n");
        int ans = answerfind(arr, cost, n, m, h, inheap);
        printf("%d\n", ans);
    }
}