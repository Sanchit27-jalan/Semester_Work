#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    int key;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode *PtrNode;
typedef PtrNode Tree;

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

void reverse(que q)
{
    if (q->num == 0)
    {
        return;
    }
    else
    {
        int c = q->num;
        for (int i = 0; i < c / 2; ++i)
        {
            Tree tmp = q->q_elems[q->front + i];
            q->q_elems[q->front + i] = q->q_elems[q->rear - i];
            q->q_elems[q->rear - i] = tmp;
        }
        return;
    }
}

PtrNode makenode(int e)
{
    Tree t = (Tree)malloc(sizeof(struct treenode));
    t->key = e;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Tree insert(Tree t, int e)
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

void preorder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->key);
        preorder(T->left);
        preorder(T->right);
    }
    return;
}

void beautiful(que q, int flag)
{
    int t = q->num;
    Tree p = dequeue(q);
    for (int i = 0; i < t; ++i)
    {
        if (flag == 1)
        {
            if (p->right != NULL)
            {
                enqueue(q, p->right);
            }
            if (p->left != NULL)
            {
                enqueue(q, p->left);
            }
        }
        else
        {
            if (p->left != NULL)
            {
                enqueue(q, p->left);
            }
            if (p->right != NULL)
            {
                enqueue(q, p->right);
            }
        }
        printf("%d ", p->key);
        if (i != (t - 1))
        {
            p = dequeue(q);
        }
    }
    reverse(q);
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
    int o;
    scanf("%d", &o);
    for (int f = 0; f < o; ++f)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        Tree t = NULL;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            t = insert(t, arr[i]);
        }
        que q = in(100010);
        enqueue(q, t);
        int g = height(t);
        int flag = 0;
        for (int i = 0; i < g; ++i)
        {
            beautiful(q, flag);
            if (flag == 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        printf("\n");
    }
}