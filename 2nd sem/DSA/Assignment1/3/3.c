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
    return ;
}
int main()
{
    int n;
    int arr[n];
    Tree t=NULL;
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
        t=insert(t,arr[i]);
    }
    preorder(t);
    
}