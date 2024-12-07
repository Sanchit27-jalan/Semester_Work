#include <stdio.h>
#include <stdlib.h>

struct co
{
    int x;
    int y;
};

struct queue
{
    int num;
    int max;
    int front;
    int rear;
    struct co *q_elems;
};

typedef struct queue *que;
que in(int max_el)
{
    que q;
    q = (que)malloc(sizeof(struct queue));
    q->q_elems = (struct co *)malloc(max_el * (sizeof(struct co)));
    q->max = max_el;
    q->front = 0;
    q->rear = -1;
    q->num = 0;
    return q;
}

void enqueue(que q, struct co t)
{
    if (q->num == (q->max))
    {
        return;
    }
    else
    {
        q->rear++;
        q->q_elems[q->rear] = t;
        q->num++;
    }
    return;
}

struct co dequeue(que q)
{
    if (q->num == 0)
    {
        struct co g;
        g.x = -1;
        g.y = -1;
        return g;
    }
    else
    {
        struct co t = q->q_elems[q->front];
        q->front = q->front + 1;
        q->num--;
        return t;
    }
}

int upcheck(que q, int **fertile, int **visited, int x, int y, int cost, int n, int m)
{
    if (x != 0)
    {
        if (fertile[x - 1][y] == 1)
        {
            cost = cost + 1;
            struct co n;
            n.x = x - 1;
            n.y = y;
            if (visited[x - 1][y] == 0)
            {
                enqueue(q, n);
                visited[x - 1][y] = 1;
            }
            // printf("wtfup\n");
        }
    }
    // printf("%d \n",cost);
    return cost;
}

int downcheck(que q, int **fertile, int **visited, int x, int y, int cost, int n, int m)
{
    if (x != (n - 1))
    {
        if (fertile[x + 1][y] == 1)
        {
            cost = cost + 1;
            struct co n;
            n.x = x + 1;
            n.y = y;
            if (visited[x + 1][y] == 0)
            {
                enqueue(q, n);
                visited[x + 1][y] = 1;
            }
            // printf("wtfdown\n");
        }
    }
    // printf("%d \n",cost);
    return cost;
}

int rightcheck(que q, int **fertile, int **visited, int x, int y, int cost, int n, int m)
{
    if (y != (m - 1))
    {
        if (fertile[x][y + 1] == 1)
        {
            cost = cost + 1;
            struct co n;
            n.x = x;
            n.y = y + 1;
            if (visited[x][y + 1] == 0)
            {
                enqueue(q, n);
                visited[x][y + 1] = 1;
            }
            // printf("wtfright\n");
        }
    }
    // printf("%d \n",cost);
    return cost;
}

int leftcheck(que q, int **fertile, int **visited, int x, int y, int cost, int n, int m)
{
    if (y != (0))
    {
        if (fertile[x][y - 1] == 1)
        {
            cost++;
            struct co n;
            n.x = x;
            n.y = y - 1;
            if (visited[x][y - 1] == 0)
            {
                enqueue(q, n);
                visited[x][y - 1] = 1;
            }
            // printf("wtfleft\n");
        }
    }
    // printf("%d \n",cost);
    return cost;
}

int costcalucator(que q, int **fertile, int **visited, int x, int y, int cost, int n, int m)
{
    cost = upcheck(q, fertile, visited, x, y, cost, n, m);
    cost = downcheck(q, fertile, visited, x, y, cost, n, m);
    cost = rightcheck(q, fertile, visited, x, y, cost, n, m);
    cost = leftcheck(q, fertile, visited, x, y, cost, n, m);
    // printf("%d \n",cost);
    return cost;
}

int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int **fertilematrix = malloc(sizeof(int *) * n);
    int **visitedmatrix = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        fertilematrix[i] = malloc(sizeof(int) * m);
        visitedmatrix[i] = malloc(sizeof(int) * m);
    }
    int **inputco = malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++)
    {
        inputco[i] = malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fertilematrix[i][j] = 0;
            visitedmatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < r; i++)
    {
        scanf("%d %d", &inputco[i][0], &inputco[i][1]);
        inputco[i][0]--;
        inputco[i][1]--;
        fertilematrix[inputco[i][0]][inputco[i][1]] = 1;
    }
    que q = in(r + 10);
    int i = 0;
    int cost = 0;
    while (i < r)
    {
        int x = inputco[i][0];
        int y = inputco[i][1];
        int c_this = 0;
        if (visitedmatrix[x][y] == 0)
        {
            visitedmatrix[x][y] = 1;
            struct co t;
            t.x = x;
            t.y = y;
            enqueue(q, t);
            while (q->num != 0)
            {
                struct co now = dequeue(q);
                visitedmatrix[now.x][now.y] = 1;
                // printf("Now on %d %d \n",now.x,now.y);
                c_this = costcalucator(q, fertilematrix, visitedmatrix, now.x, now.y, c_this, n, m);
                i++;
            }
            if (c_this > cost)
            {
                cost = c_this;
            }
        }
        else
        {
            i++;
        }
        // printf("iteration ended\n");
        // printf("%d \n",cost);
    }
    for(int i=0;i<r;i++){
        free(inputco[i]);
    }
    free(inputco); 
    for(int i=0;i<n;i++){
        free(fertilematrix[i]);
        free(visitedmatrix[i]);
    }
    free(fertilematrix);
    free(visitedmatrix);
    printf("%d\n", cost);
}