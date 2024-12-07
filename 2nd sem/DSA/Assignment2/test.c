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

void preorder(Tree t){
    if(t==NULL){
        return;
    }
    else{
        printf("%lld ",t->key);
        preorder(t->left);
        preorder(t->right);
        return;
    }
}
void postorder(Tree t){
    if(t==NULL){
        // printf("wtf\n");
        return;
    }
    else{
        postorder(t->left);
        postorder(t->right);
        printf("%lld ",t->key);
        return;
    }
}
void inorder(Tree t){
    if(t==NULL){
        return;
    }
    else{
        inorder(t->left);
        printf("%lld ",t->key);
        inorder(t->right);
        return;
    }
}

Tree min(Tree t){
    if(t==NULL){
        return t;
    }
    else if(t!=NULL && t->left==NULL){
        return t;
    }
    else{
        return(min(t->left));
    }
}
Tree delete(Tree t,int a){
    if(t==NULL){
        return t;
    }
    else{
        if(t->key>a){
            t->left=delete(t->left,a);
        }
        else if(t->key<a){
            t->right=delete(t->right,a);
        }
        else{
            if(t->left==NULL && t->right==NULL){
                free(t);
                return NULL;
            }
            else if(t->left!=NULL && t->right==NULL){
                Tree temp=t;
                t=t->left;
                free(temp);
                return t;
            }
            else if(t->left==NULL && t->right!=NULL){
                Tree temp=t;
                t=t->right;
                free(temp);
                return t;
            }
            else{
                Tree s=min(t->right);
                t->key=s->key;
                t->right=delete(t->right,s->key);
                return t;
            }
            return t;
        }
        return t;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    long long int arr[n];
    Tree t = NULL;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
        t = insert(t, arr[i]);
    }
    Tree s=delete(t,10);
    preorder(t);
    printf("\n");
} 