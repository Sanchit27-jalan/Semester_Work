#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    long long int key;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode *PtrNode;
typedef PtrNode Tree;

PtrNode makenode(long long int e)
{
    Tree t = (Tree)malloc(sizeof(struct treenode));
    t->key = e;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Tree insert(Tree t, long long int e)
{
    if (t == NULL)
    {
        t = makenode(e);
        return t;
    }
    else if (t->key > e)
    {
        t->left = insert(t->left, e);
    }
    else if (t->key < e)
    {
        t->right = insert(t->right, e);
    }
    return t;
}

long long int h = 0;
long long int sum(Tree t, long long int n)
{
    if (t == NULL)
    {
        return n;
    }
    if (t != NULL && t->left == NULL && t->right == NULL)
    {
        t->key = t->key + n;
        h = h + t->key;
        return t->key;
    }
    else
    {
        long long int d = sum(t->left, n);
        t->key = t->key + d;
        d = t->key;
        h = h + t->key;
        long long int e = sum(t->right, d);
        return e;
    }
}
struct queue
{
    int num;
    int max;
    int front;
    int rear;
    Tree *q_elems;
};

typedef struct queue *que;
que in(int max_el)
{
    que q;
    q = (que)malloc(sizeof(struct queue));
    q->q_elems = (Tree *)malloc(max_el * (sizeof(Tree)));
    q->max = max_el;
    q->front = 0;
    q->rear = -1;
    q->num = 0;
    return q;
}

void enqueue(que q, Tree t)
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

Tree dequeue(que q)
{
    if (q->num == 0)
    {
        return NULL;
    }
    else
    {
        Tree t = q->q_elems[q->front];
        q->front = q->front + 1;
        q->num--;
        return t;
    }
    return NULL;
}

void levelorder(que q)
{
    int t = q->num;
    Tree p = dequeue(q);
    for (int i = 0; i < t; ++i)
    {
        if (p->left != NULL)
        {
            enqueue(q, p->left);
        }
        if (p->right != NULL)
        {
            enqueue(q, p->right);
        }
        printf("%lld ", p->key);
        if (i != (t - 1))
        {
            p = dequeue(q);
        }
    }
}

int height(Tree t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        int left_ht = height(t->left);
        int right_ht = height(t->right);
        if (left_ht > right_ht)
        {
            return (left_ht + 1);
        }
        else
        {
            return (right_ht + 1);
        }
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    long long int arr[n];
    Tree t = NULL;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
        t = insert(t, arr[i]);
    }
    long long int f = sum(t, 0);
    que q = in(1000100);
    enqueue(q, t);
    int g = height(t);
    for(int i=0;i<g;++i){
        levelorder(q);
    }
    printf("\n");
    printf("%lld \n", h);
}
