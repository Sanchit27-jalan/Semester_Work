#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    int wt;
    struct node *next;
};

struct graph
{
    int vertices;
    struct node **table;
};

typedef struct graph *graph;

graph creategraph(int n)
{
    graph g = malloc(sizeof(struct graph));
    g->vertices = n;
    g->table = (struct node **)malloc(sizeof(struct node *) * (n + 1));
    for (int i = 0; i < (n + 1); ++i)
    {
        g->table[i] = (struct node *)malloc(sizeof(struct node));
        g->table[i]->vertex = -1;
        g->table[i]->next = NULL;
        g->table[i]->wt = 10000;
    }
    return g;
}

void insertgraph(graph g, int u, int v, int wt)
{
    struct node *new = malloc(sizeof(struct node));
    new->vertex = v;
    new->next = NULL;
    new->wt = wt;
    struct node *temp = g->table[u];
    new->next = temp->next;
    temp->next = new;
    return;
}
struct he
{
    int u;
    int v;
    int wt;
};
struct stheap
{
    int size;
    int capacity;
    struct he *elements;
};

typedef struct stheap *heap;
heap create(int cap)
{
    heap h;
    h = malloc(sizeof(struct stheap));
    h->size = 0;
    h->capacity = cap;
    h->elements = (struct he *)malloc(sizeof(struct he) * cap);
    return h;
}
void insert(heap h, struct he n)
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
            if (h->elements[i].wt > h->elements[i / 2].wt)
            {
                break;
            }
            else
            {
                struct he temp = h->elements[i];
                h->elements[i] = h->elements[i / 2];
                h->elements[i / 2] = temp;
            }
        }
        h->size++;
    }
    return;
}

struct he extracting_min_to_last(heap h)
{
    struct he n = h->elements[1];
    struct he x = h->elements[h->size];
    h->elements[1] = x;
    h->elements[h->size] = n;
    int i = 1;
    while (i * 2 < h->size)
    {
        int j = 2 * i;
        if ((j + 1) == h->size)
        {
            if (h->elements[i].wt <= h->elements[j].wt)
            {
                break;
            }
            else
            {
                struct he temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }
        }
        else if ((j + 1) < h->size)
        {
            if (h->elements[j].wt < h->elements[j + 1].wt && h->elements[i].wt > h->elements[j].wt)
            {
                struct he temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i = j;
            }
            else if (h->elements[j + 1].wt < h->elements[j].wt && h->elements[i].wt > h->elements[j + 1].wt)
            {
                struct he temp = h->elements[i];
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

void inserting(graph g, heap h, int *visited,int x,int y)
{
    // struct he extract = extracting_min_to_last(h);
    // int x = extract.u;
    // int y = extract.v;
    struct node *xlist = g->table[x]->next;
    struct node *ylist = g->table[y]->next;
    if (visited[x] == 0)
    {
        visited[x]=1;
        while (xlist != NULL)
        {
            if(visited[ylist->vertex]==0){
                if (xlist->vertex != y)
                {
                    // printf("wtf1\n");
                    struct he new;
                    new.u = x;
                    new.v = xlist->vertex;
                    new.wt = xlist->wt;
                    insert(h, new);
                }
            }
            xlist = xlist->next;
        }
    }
    if(y==4){
        printf("%d\n",visited[y]);
    }
    // printf("%d\n",visited[y]);
    if (visited[y] == 0)
    {
        visited[y]=1;
        while (ylist != NULL)
        {
            // if(y==4){
            //     printf(" 4 index: %d\n",ylist->vertex);
            // }
            if(visited[ylist->vertex]==0){
                if (ylist->vertex != x)
                {
                    // printf("wtf2\n");
                    struct he new;
                    new.u = y;
                    new.v = ylist->vertex;
                    new.wt = ylist->wt;
                    insert(h, new);
                }
            }
            ylist=ylist->next;
        }
    }
    for(int i=1;i<=h->size;i++){
        printf("%d %d %d\n",h->elements[i].u,h->elements[i].v,h->elements[i].wt);
    }
    // struct he extract = extracting_min_to_last(h);
}

int main()
{
    int n, m;
    // n=5;
    // m=5;
    scanf("%d %d", &n, &m);
    graph g = creategraph(n);
    heap h = create(m + 1);
    int minw = 10000;
    int vmin = 0;
    int umin = 0;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        insertgraph(g, u, v, w);
        insertgraph(g, v, u, w);
        if (w < minw)
        {
            minw = w;
            vmin = v;
            umin = u;
        }
    }
    int *visited = malloc(sizeof(int) * (n + 1));
    int i=1;
    int cost=0;
    struct he l;
    l.u=umin;
    l.v=vmin;
    l.wt=minw;
    insert(h,l);
    while(i!=(n)){
        for(int i=1;i<=n;i++){
            printf("%d ",visited[i]);
        }
        printf("\n");
        // printf("%d\n",i);
        // printf("heap size: %d\n",h->size);
        // printf("heap size: %d\n",h->size);
        struct he new=extracting_min_to_last(h);
        printf("heaped out: %d %d\n",new.u,new.v);
        inserting(g,h,visited,new.u,new.v);
        if(visited[new.u]==1 && visited[new.v]==1){
            continue;
        }
        else{
            i++;
        }
        // else{
        //     int b=new.u;
        //     int r=new.v;
        //     if(b==umin){
        //         umin=new.v;
        //     }
        //     else if(b==vmin){
        //         vmin=new.v;
        //     }
        //     else if(r==umin){
        //         umin=b;
        //     }
        //     else{
        //         vmin=b;
        //     }
        //     i++;
        //     cost=cost+new.wt;
        //     // printf("%d \n",cost);
        // }
        printf("%d \n",cost);
    }
    printf("%d \n",cost);
}