#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    int key;
    struct treenode *left1;
    struct treenode *right1;
};
typedef struct treenode *PtrNode;
typedef PtrNode Tree;

PtrNode makenode(int e)
{
    Tree t = (Tree)malloc(sizeof(struct treenode));
    t->key = e;
    t->left1 = NULL;
    t->right1 = NULL;
    return t;
}

Tree making(int *in, int in_len, int *pre, int pre_len, int root)
{
    if (in_len == 0)
    {
        return NULL;
    }
    Tree t = makenode(root);
    if (in_len == 1)
    {
        return t;
    }
    int i=0;
    while(in[i]!=root){
        i++;
    }
    i = i + 1;
    int j=0;
    while (i < in_len)
    {
        i++;
        j++;
    }
    int *left = (int *)malloc(sizeof(int) * i);
    int *right = (int *)malloc(sizeof(int) * j);
    i = 0;
    int leftlen = 0, rightlen = 0;
    while (in[i] != root)
    {
        left[leftlen] = in[i];
        i++;
        leftlen++;
    }
    i = i + 1;
    while (i < in_len)
    {
        right[rightlen] = in[i];
        i++;
        rightlen++;
    }
    int leftprelen=0,rightprelen=0;
    for(int i=0;i<pre_len;++i){
        int flag=0;
        for(int j=0;j<leftlen;++j){
            if(left[j]==pre[i]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            // left_pre[leftprelen]=pre[i];
            leftprelen++;
        }
    }
    int *left_pre = (int *)malloc(sizeof(int) * leftprelen);
    leftprelen=0;
    for(int i=0;i<pre_len;++i){
        int flag=0;
        for(int j=0;j<leftlen;++j){
            if(left[j]==pre[i]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            left_pre[leftprelen]=pre[i];
            leftprelen++;
        }
    }
    for(int i=0;i<pre_len;++i){
        int flag=0;
        for(int j=0;j<rightlen;++j){
            if(right[j]==pre[i]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            // right_pre[rightprelen]=pre[i];
            rightprelen++;
        }
    }
    int *right_pre = (int *)malloc(sizeof(int) * rightprelen);
    rightprelen=0;
    for(int i=0;i<pre_len;++i){
        int flag=0;
        for(int j=0;j<rightlen;++j){
            if(right[j]==pre[i]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            right_pre[rightprelen]=pre[i];
            rightprelen++;
        }
    }
    int leftroot, rightroot;
    leftroot = pre[1];
    rightroot = pre[leftlen + 1];
    free(pre);
    free(in);
    t->left1 = making(left, leftlen, left_pre, leftprelen, leftroot);
    t->right1 = making(right, rightlen,right_pre,rightprelen,rightroot);
    // free(left);
    // free(right);
    // free(left_pre);
    // free(right_pre);
    return t;
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
        if (p->left1 != NULL)
        {
            enqueue(q, p->left1);
        }
        if (p->right1 != NULL)
        {
            enqueue(q, p->right1);
        }
        printf("%d ", p->key);
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
        int left_ht = height(t->left1);
        int right_ht = height(t->right1);
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
void treefree(Tree t)
{
    if (t == NULL)
    {
        return;
    }
    treefree(t->left1);
    treefree(t->right1);
    free(t);
    return;
}
void freeque(que q)
{
    free(q->q_elems);
    free(q);
}
int main()
{
    int f;
    scanf("%d", &f);
    for (int i = 0; i < f; ++i)
    {
        int n;
        scanf("%d", &n);
        int *inorder = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &inorder[j]);
        }
        int *preorder = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &preorder[j]);
        }
        int root = preorder[0];
        Tree t = making(inorder, n, preorder, n, root);
        que q = in(1010);
        enqueue(q, t);
        int g = height(t);
        for (int i = 0; i < g; ++i)
        {
            levelorder(q);
        }
        printf("\n");
        treefree(t);
        // free(inorder);
        // free(preorder);
        freeque(q);
    }
}