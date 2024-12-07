#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct graph{
    int vertices;
    struct node** table;
};

typedef struct graph* graph;

graph creategraph(int n){
    graph g=malloc(sizeof(struct graph));
    g->vertices=n;
    g->table=(struct node**)malloc(sizeof(struct node*)*(n+1));
    for(int i=0;i<(n+1);++i){
        g->table[i]=(struct node*)malloc(sizeof(struct node));
        g->table[i]->vertex=-1;
        g->table[i]->next=NULL;
    }
    return g;
}

void insertgraph(graph g,int u,int v){
    struct node* new=malloc(sizeof(struct node));
    new->vertex=v;
    new->next=NULL;
    struct node* temp=g->table[u];
    new->next=temp->next;
    temp->next=new;
    return;
}
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
            if (h->elements[i] > h->elements[i / 2])
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

int extracting_min_to_last(heap h)
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
                i=j;
            }
        }
        else if ((j + 1) < h->size)
        {
            if (h->elements[j] < h->elements[j + 1] && h->elements[i] > h->elements[j])
            {
                int temp = h->elements[i];
                h->elements[i] = h->elements[j];
                h->elements[j] = temp;
                i=j;
            }
            else if (h->elements[j + 1] < h->elements[j] && h->elements[i] > h->elements[j + 1])
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
    return n;
}
void vertextraversal(graph g,int *pushed,int* answer,int filled,int vertex,heap h){  
    if(pushed[vertex]==0){
        insert(h,vertex);
        pushed[vertex]=1;
    }
    answer[filled]=vertex;
    struct node* temp=g->table[vertex]->next;
    // int n=extracting_min_to_last(h);
    while(temp!=NULL){
        if(pushed[temp->vertex]==0){
            insert(h,temp->vertex);
            pushed[temp->vertex]=1;
        }
        temp=temp->next;
    }
    return;


}
int main(){
    int n,m;
    // n=5;
    // m=5;
    scanf("%d %d",&n,&m);
    graph g=creategraph(n);
    heap h=create(n+1);
    int u,v;
    for(int i=0;i<m;++i){
        scanf("%d %d",&u,&v);
        insertgraph(g,u,v);
        insertgraph(g,v,u);

    }
    // insertgraph(g,1,4);
    // insertgraph(g,4,1);
    // insertgraph(g,3,4);
    // insertgraph(g,4,3);
    // insertgraph(g,5,4);
    // insertgraph(g,4,5);
    // insertgraph(g,2,3);
    // insertgraph(g,3,2);
    // insertgraph(g,1,5);
    // insertgraph(g,5,1);
    int *pushed=malloc(sizeof(int)*(n+1));
    int *answer=malloc(sizeof(int)*n);
    int filled=0;
    int vertex=1;
    pushed[1]=1;
    for(int i=0;i<n;++i){
        vertextraversal(g,pushed,answer,filled,vertex,h);
        vertex=extracting_min_to_last(h);
        filled++;
    }
    for(int i=0;i<n;++i){
        printf("%d ",answer[i]);
    }
    printf("\n");
    free(pushed);
    free(answer);
}