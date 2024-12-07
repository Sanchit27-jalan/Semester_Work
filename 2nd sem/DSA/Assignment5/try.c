#include <stdio.h>
#include <stdlib.h>
#define int short int

typedef struct queue *Queue;
struct node
{
    int x;
    int y;
    struct node *prev;
    struct node *next;
};
typedef struct node *node;
struct queue
{
    struct node *front;
    struct node *rear;
    int number;
};

void Push(Queue head,int x,int y)
{
    node new = (node)malloc(1 * sizeof(struct node));
    new->x=x;
    new->y=y;
    if (head->front == NULL)
    {
        head->front = new;
        head->rear = new;
        head->number++;
        new->next = new;
        new->prev = new;
    }
    else
    {
        node temp = head->rear;
        head->rear = new;
        new->prev = temp;
        new->next = head->front;
        head->front->prev = new;
        head->number++;
        temp->next = new;
    }
    return;
}

void Inject(Queue head,int x,int y)
{
    node new = (node)malloc(1 * sizeof(struct node));
    new->x=x;
    new->y=y;
    if (head->front == NULL)
    {
        head->front = new;
        head->rear = new;
        head->number++;
        new->next = new;
        new->prev = new;
    }
    else
    {
        node temp = head->front;
        head->front = new;
        new->next = temp;
        temp->prev = new;
        head->rear->next = new;
        new->prev = head->rear;
        head->number++;
    }
    return;
}

struct node* Pop(Queue head)
{
    if (head->number == 0)
    {
        return NULL;
    }
    else if (head->number == 1)
    {
        struct node* t=malloc(sizeof(struct node)) ;
        int x = head->front->x;
        int y = head->front->y;
        t->x=x;
        t->y=y;
        head->front = NULL;
        head->rear = NULL;
        head->number = 0;
        return (t);
    }
    else
    {
        node temp = head->front;
        head->front = temp->next;
        head->rear->next = head->front;
        head->front->prev = head->rear;
        head->number--;
        return (temp);
    }
}

void left(int** heightmatrix,int p,int q,int **cost,Queue Qu){
    if(q==0){
        return;
    }
    else{
        int c=heightmatrix[p][q]-heightmatrix[p][q-1];
        if(c!=0){
            c=1;
        }
        if(cost[p][q-1]>c+cost[p][q]){
            cost[p][q-1]=c+cost[p][q];
            if(c==0){
                Inject(Qu,p,q-1);
            }
            else{
                Push(Qu,p,q-1);
            }
        }
    }
    return;
}


void right(int** heightmatrix,int p,int q,int **cost,Queue Qu,int n,int m){
    if(q==(m-1)){
        return;
    }
    else{
        int c=heightmatrix[p][q]-heightmatrix[p][q+1];
        if(c!=0){
            c=1;
        }
        if(cost[p][q+1]>c+cost[p][q]){
            cost[p][q+1]=c+cost[p][q];
            if(c==0){
                Inject(Qu,p,q+1);
            }
            else{
                Push(Qu,p,q+1);
            }
        }
    }
    return;
}
void up(int** heightmatrix,int p,int q,int **cost,Queue Qu){
    if(p==0){
        return;
    }
    else{
        int c=heightmatrix[p][q]-heightmatrix[p-1][q];
        if(c!=0){
            c=1;
        }
        if(cost[p-1][q]>c+cost[p][q]){
            cost[p-1][q]=c+cost[p][q];
            if(c==0){
                Inject(Qu,p-1,q);
            }
            else{
                Push(Qu,p-1,q);
            }
        }
    }
    return;
}
void down(int** heightmatrix,int p,int q,int **cost,Queue Qu,int n,int m){
    if(p==(n-1)){
        return;
    }
    else{
        int c=heightmatrix[p][q]-heightmatrix[p+1][q];
        if(c!=0){
            c=1;
        }
        if(cost[p+1][q]>c+cost[p][q]){
            cost[p+1][q]=c+cost[p][q];
            if(c==0){
                Inject(Qu,p+1,q);
            }
            else{
                Push(Qu,p+1,q);
            }
        }
    }
    return;
}
void traversal(int** heightmatrix,int p,int q,int **cost,Queue Qu,int n,int m){
    left(heightmatrix,p,q,cost,Qu);
    right(heightmatrix,p,q,cost,Qu,n,m);
    up(heightmatrix,p,q,cost,Qu);
    down(heightmatrix,p,q,cost,Qu,n,m);
    return;
}


signed main(){
    int t;
    scanf("%hd", &t);
    while (t > 0)
    {
        t--;
        int n, m;
        scanf("%hd %hd", &n, &m);
        int **heightmatrix = malloc(sizeof(int *) * n);
        int **cost = malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
            heightmatrix[i] = (int *)malloc(sizeof(int) * m);
            cost[i] = (int *)malloc(sizeof(int) * m);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%hd", &heightmatrix[i][j]);
                cost[i][j]=5000;
            }
        }
        Queue head = (Queue)malloc(sizeof(struct queue));
        head->front = NULL;
        head->rear = NULL;
        head->number = 0;
        cost[0][0]=0;
        Inject(head,0,0);
        while(head->number!=0){
            struct node* now=Pop(head);
            int p = now->x;
            int qu = now->y;
            traversal(heightmatrix,p,qu,cost,head,n,m);
        }
        printf("%hd\n", cost[n-1][m-1]);
    }
}