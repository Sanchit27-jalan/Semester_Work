#include <stdio.h>
#include <stdlib.h>

struct cost_and_co_ordinates
{
    int cost;
    int x;
    int y;
};

typedef struct cost_and_co_ordinates c;
struct matrix
{
    c *left;
    c *right;
    c *up;
    c *down;
    int visited;
    int cost;
};

typedef struct queue *Queue;
struct node
{
    int element;
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

void Push(Queue head, int val,int x,int y)
{
    node new = (node)malloc(1 * sizeof(struct node));
    new->element = val;
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

void Inject(Queue head, int val,int x,int y)
{
    node new = (node)malloc(1 * sizeof(struct node));
    new->element = val;
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
        int c = head->front->element;
        int x = head->front->x;
        int y = head->front->y;
        t->x=x;
        t->element=c;
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
struct matrix **matrixform(int **heightmatrix, int n, int m)
{
    struct matrix **elevator = malloc(sizeof(struct matrix *) * n);
    for (int i = 0; i < n; i++)
    {
        elevator[i] = (struct matrix *)malloc(sizeof(struct matrix) * m);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            elevator[i][j].right = malloc(sizeof(c));
            elevator[i][j].up = malloc(sizeof(c));
            elevator[i][j].left = malloc(sizeof(c));
            elevator[i][j].down = malloc(sizeof(c));
            elevator[i][j].visited = 0;
            elevator[i][j].cost = 31999;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                elevator[i][j].left = NULL;
                elevator[i][j].up = NULL;
                if (heightmatrix[i][j + 1] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].right->cost = 0;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                else
                {
                    elevator[i][j].right->cost = 1;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                if (heightmatrix[i + 1][j] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].down->cost = 0;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
                else
                {
                    elevator[i][j].down->cost = 1;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
            }
            else if (i == 0 && j == (m - 1))
            {
                elevator[i][j].right = NULL;
                elevator[i][j].up = NULL;
                elevator[i][j].left->x = i;
                elevator[i][j].left->y = j - 1;
                elevator[i][j].down->x = i + 1;
                elevator[i][j].down->y = j;
                if (heightmatrix[i][j - 1] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].left->cost = 0;
                }
                else
                {
                    elevator[i][j].left->cost = 1;
                }
                if (heightmatrix[i + 1][j] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].down->cost = 0;
                }
                else
                {
                    elevator[i][j].down->cost = 1;
                }
            }
            else if (i == (n - 1) && j == 0)
            {
                elevator[i][j].left = NULL;
                elevator[i][j].down = NULL;
                elevator[i][j].right->x = i;
                elevator[i][j].right->y = j + 1;
                elevator[i][j].up->x = i - 1;
                elevator[i][j].up->y = j;
                if (heightmatrix[i][j + 1] == heightmatrix[i][j])
                {
                    elevator[i][j].right->cost = 0;
                }
                else
                {
                    elevator[i][j].right->cost = 1;
                }
                if (heightmatrix[i - 1][j] == heightmatrix[i][j])
                {
                    elevator[i][j].up->cost = 0;
                }
                else
                {
                    elevator[i][j].up->cost = 1;
                }
            }
            else if (i == (n - 1) && j == (m - 1))
            {
                elevator[i][j].right = NULL;
                elevator[i][j].down = NULL;
                elevator[i][j].left->x = i;
                elevator[i][j].left->y = j - 1;
                elevator[i][j].up->x = i - 1;
                elevator[i][j].up->y = j;
                if (heightmatrix[i][j - 1] == heightmatrix[i][j])
                {
                    elevator[i][j].left->cost = 0;
                }
                else
                {
                    elevator[i][j].left->cost = 1;
                }
                if (heightmatrix[i - 1][j] == heightmatrix[i][j])
                {
                    elevator[i][j].up->cost = 0;
                }
                else
                {
                    elevator[i][j].up->cost = 1;
                }
            }
            else if (i == 0)
            {
                elevator[i][j].up = NULL;
                if (heightmatrix[i][j + 1] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].right->cost = 0;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                else
                {
                    elevator[i][j].right->cost = 1;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                if (heightmatrix[i][j - 1] == heightmatrix[i][j])
                {
                    elevator[i][j].left->cost = 0;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                else
                {
                    elevator[i][j].left->cost = 1;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                if (heightmatrix[i + 1][j] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].down->cost = 0;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
                else
                {
                    elevator[i][j].down->cost = 1;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
            }
            else if (j == 0)
            {
                elevator[i][j].left = NULL;
                if (heightmatrix[i][j + 1] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].right->cost = 0;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                else
                {
                    elevator[i][j].right->cost = 1;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                if (heightmatrix[i - 1][j] == heightmatrix[i][j])
                {
                    elevator[i][j].up->cost = 0;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
                else
                {
                    elevator[i][j].up->cost = 1;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
                if (heightmatrix[i + 1][j] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].down->cost = 0;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
                else
                {
                    elevator[i][j].down->cost = 1;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
            }
            else if (i == (n - 1))
            {
                elevator[i][j].down = NULL;
                if (heightmatrix[i][j - 1] == heightmatrix[i][j])
                {
                    elevator[i][j].left->cost = 0;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                else
                {
                    elevator[i][j].left->cost = 1;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                if (heightmatrix[i][j + 1] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].right->cost = 0;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                else
                {
                    elevator[i][j].right->cost = 1;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                if (heightmatrix[i - 1][j] == heightmatrix[i][j])
                {
                    elevator[i][j].up->cost = 0;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
                else
                {
                    elevator[i][j].up->cost = 1;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
            }
            else if (j == (m - 1))
            {
                elevator[i][j].right = NULL;
                if (heightmatrix[i][j - 1] == heightmatrix[i][j])
                {
                    elevator[i][j].left->cost = 0;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                else
                {
                    elevator[i][j].left->cost = 1;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                if (heightmatrix[i - 1][j] == heightmatrix[i][j])
                {
                    elevator[i][j].up->cost = 0;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
                else
                {
                    elevator[i][j].up->cost = 1;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
                if (heightmatrix[i + 1][j] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].down->cost = 0;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
                else
                {
                    elevator[i][j].down->cost = 1;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
            }
            else
            {
                if (heightmatrix[i][j - 1] == heightmatrix[i][j])
                {
                    elevator[i][j].left->cost = 0;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                else
                {
                    elevator[i][j].left->cost = 1;
                    elevator[i][j].left->x = i;
                    elevator[i][j].left->y = j - 1;
                }
                if (heightmatrix[i][j + 1] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].right->cost = 0;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                else
                {
                    elevator[i][j].right->cost = 1;
                    elevator[i][j].right->x = i;
                    elevator[i][j].right->y = j + 1;
                }
                if (heightmatrix[i - 1][j] == heightmatrix[i][j])
                {
                    elevator[i][j].up->cost = 0;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
                else
                {
                    elevator[i][j].up->cost = 1;
                    elevator[i][j].up->x = i - 1;
                    elevator[i][j].up->y = j;
                }
                if (heightmatrix[i + 1][j] - heightmatrix[i][j] == 0)
                {
                    elevator[i][j].down->cost = 0;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
                else
                {
                    elevator[i][j].down->cost = 1;
                    elevator[i][j].down->x = i + 1;
                    elevator[i][j].down->y = j;
                }
            }
        }
    }
    return elevator;
}
void elementtraversal(struct matrix **elevator, int p, int q, Queue qu)
{
    if (elevator[p][q].left != NULL)
    {
        if (elevator[p][q - 1].cost > elevator[p][q].cost + elevator[p][q].left->cost)
        {
            elevator[p][q - 1].cost = elevator[p][q].cost + elevator[p][q].left->cost;
            // elementtraversal(elevator,p,q-1,qzero,qone);
            if (elevator[p][q].left->cost == 0)
            {
                Inject(qu,0,p,q-1);
            }
            else
            {
               Push(qu,1,p,q-1);
            }
        }
        // if (elevator[p][q - 1].visited == 0)
        // {
        //     // enqueue(qu, elevator[p][q].left);
        //     elevator[p][q - 1].visited = 1;
        //     if (elevator[p][q].left->cost == 0)
        //     {
        //         enqueue(qzero, elevator[p][q].left);
        //     }
        //     else
        //     {
        //         enqueue(qone, elevator[p][q].left);
        //     }
        // }
    }
    if (elevator[p][q].down != NULL)
    {
        if (elevator[p + 1][q].cost > elevator[p][q].cost + elevator[p][q].down->cost)
        {
            elevator[p + 1][q].cost = elevator[p][q].cost + elevator[p][q].down->cost;
            // elementtraversal(elevator,p+1,q,qzero,qone);
            if (elevator[p][q].down->cost == 0)
            {
                Inject(qu,0,p+1,q);
            }
            else
            {
                Push(qu,1,p+1,q);
            }
        }
        // if (elevator[p + 1][q].visited == 0)
        // {
        //     // enqueue(qu, elevator[p][q].down);
        //     elevator[p + 1][q].visited = 1;
        //     if (elevator[p][q].down->cost == 0)
        //     {
        //         enqueue(qzero, elevator[p][q].down);
        //     }
        //     else
        //     {
        //         enqueue(qone, elevator[p][q].down);
        //     }
        // }
    }
    if (elevator[p][q].up != NULL)
    {
        if (elevator[p - 1][q].cost > elevator[p][q].cost + elevator[p][q].up->cost)
        {
            elevator[p - 1][q].cost = elevator[p][q].cost + elevator[p][q].up->cost;
            // elementtraversal(elevator,p-1,q,qzero,qone);
            if (elevator[p][q].up->cost == 0)
            {
                Inject(qu,0,p-1,q);
            }
            else
            {
                Push(qu,1,p-1,q);
            }
        }
        // if (elevator[p - 1][q].visited == 0)
        // {
        //     // enqueue(qu, elevator[p][q].up);
        //     elevator[p - 1][q].visited = 1;
        //     if (elevator[p][q].up->cost == 0)
        //     {
        //         enqueue(qzero, elevator[p][q].up);
        //     }
        //     else
        //     {
        //         enqueue(qone, elevator[p][q].up);
        //     }
        // }
    }
    if (elevator[p][q].right != NULL)
    {
        if (elevator[p][q + 1].cost > elevator[p][q].cost + elevator[p][q].right->cost)
        {
            elevator[p][q + 1].cost = elevator[p][q].cost + elevator[p][q].right->cost;
            // elementtraversal(elevator,p,q+1,qone,qzero);
            if (elevator[p][q].right->cost == 0)
            {
                Inject(qu,0,p,q+1);
            }
            else
            {
                Push(qu,1,p,q+1);
            }
        }
        // if (elevator[p][q + 1].visited == 0)
        // {
        //     // enqueue(qu, elevator[p][q].right);
        //     elevator[p][q + 1].visited = 1;
        //     if (elevator[p][q].right->cost == 0)
        //     {
        //         enqueue(qzero, elevator[p][q].right);
        //     }
        //     else
        //     {
        //         enqueue(qone, elevator[p][q].right);
        //     }
        // }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        int n, m;
        scanf("%d %d", &n, &m);
        // n = 2;
        // m = 2;
        int **heightmatrix = malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
            heightmatrix[i] = (int *)malloc(sizeof(int) * m);
        }
        // int values[6][6] = {
        //     {1, 2, 1, 3, 3, 3},
        //     {1, 1, 1, 3, 5, 3},
        //     {1, 7, 4, 5, 3, 3},
        //     {1, 9, 2, 6, 4, 4},
        //     {11, 10, 12, 13, 4, 8},
        //     {11, 10, 12, 13, 4, 4}};
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         heightmatrix[i][j] = values[i][j];
        //     }
        // }
        // int heightmatrix[6][6]={{1,2,1,3,3,3},{1,1,1,3,5,3},{1,7,4,5,3,3},{1,9,2,6,4,4},{11,10,12,13,4,8},{11,10,12,13,4,4}};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &heightmatrix[i][j]);
            }
        }
        // heightmatrix[0][0]=1;
        // heightmatrix[0][1]=1;
        // heightmatrix[1][0]=1;
        // heightmatrix[1][1]=1;
        struct matrix **elevator = matrixform(heightmatrix, n, m);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         printf("Index is %d %d\n",i,j);
        //         struct matrix f=elevator[i][j];
        //         if(f.left!=NULL){
        //             printf("%d %d %d\n",f.left->cost,f.left->x,f.left->y);
        //         }
        //         if(f.right!=NULL){
        //             printf("%d %d %d\n",f.right->cost,f.right->x,f.right->y);
        //         }
        //         if(f.up!=NULL){
        //             printf("%d %d %d\n",f.up->cost,f.up->x,f.up->y);
        //         }
        //         if(f.down!=NULL){
        //             printf("%d %d %d\n",f.down->cost,f.down->x,f.down->y);
        //         }
        //     }
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         heightmatrix[i][j] = 31999;
        //     }
        // }
        // int **elevatormatrix = malloc(sizeof(int *) * n);
        // for (int i = 0; i < n; i++)
        // {
        //     elevatormatrix[i] = (int *)malloc(sizeof(int) * m);
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         elevatormatrix[i][j] = 0;
        //     }
        // }
        for (int i = 0; i < n; i++)
        {
            free(heightmatrix[i]);
        }
        free(heightmatrix);
        elevator[0][0].visited = 1;
        Queue head = (Queue)malloc(sizeof(struct queue));
        head->front = NULL;
        head->rear = NULL;
        head->number = 0;
        if (elevator[0][0].right->cost == 0)
        {
            Inject(head,0,0,1);
        }
        else
        {
            Push(head,1,0,1);
        }
        if (elevator[0][0].down->cost == 0)
        {
            Inject(head,0,1,0);
        }
        else
        {
             Push(head,1,1,0);
        }
        elevator[0][1].visited = 1;
        elevator[1][0].visited = 1;
        elevator[0][1].cost = elevator[0][0].right->cost;
        elevator[1][0].cost = elevator[0][0].down->cost;
        elevator[0][0].cost = 0;
        while (head->number!=0)
        {
            struct node* now=Pop(head);
            int p = now->x;
            int qu = now->y;
            elevator[p][qu].visited = 1;
            elementtraversal(elevator, p, qu,head);
            free(now);
            // printf("Co ordinates traversed is: %d %d\n", p, qu);
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         printf("%d  ", elevator[i][j].cost);
            //     }
            //     printf("\n");
            // }
            // printf("%d ",heightmatrix[n-1][m-1]);
        }
        // printf("\n");
        printf("%d\n", elevator[n - 1][m - 1].cost);
    }
    return 0;
}