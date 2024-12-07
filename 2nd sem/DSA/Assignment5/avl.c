#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct AVLNode* AVLTree;
typedef AVLTree Position;

struct AVLNode {
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int Height(Position P)
{
	if( P == NULL )
		return -1;
	else
		return P->Height;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
AVLTree MakeNode(x){
    AVLTree new=malloc(sizeof(struct AVLNode));
    new->Element=x;
    new->Height=0;
    new->Left=NULL;
    new->Right=NULL;
    return new;
}
Position SingleRotateWithLeft(Position k2)
{
	Position k1;
	
	k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;
	k2->Height = max(Height(k2->Left),Height(k2->Right)) + 1;
	k1->Height = max(Height(k1->Left),k2->Height) + 1;

	return k1; // new root
}
Position SingleRotateWithRight(Position k2){
    Position k1;
    k1=k2->Right;
    k2->Right = k1->Left;
    k1->Left=k2;
    k2->Height= max(Height(k2->Right),Height(k2->Left)) + 1;
    k1->Height=max(Height(k1->Right),k2->Height)+1;
    return k1;
}
int IsSmaller(int a,int b){
    if (a<b){
        return 1;
    }
    return 0;
}
int IsLarger(int a,int b){
    if (a>b){
        return 1;
    }
    return 0;
}

Position DoubleRotateWithLeft(Position k2)
{
	// Rotate between k3 and k1
	k2->Left = SingleRotateWithRight(k2->Left);

	// Rotate between k1 and k2
	return SingleRotateWithLeft(k2);
}

Position DoubleRotateWithRight(Position k2)
{
    k2->Right=SingleRotateWithLeft(k2->Right);
    return SingleRotateWithRight(k2);
}
AVLTree Insert(AVLTree T, ElementType X)
{
	
    if( T == NULL)
        T = MakeNode(X);
    else if ( IsSmaller(X,T->Element) ) // X < T->Element
    {
        T->Left = Insert(T->Left,X);
	// Check if AVL Property has been violated after insertion into left subtree
	if ( (Height(T->Left) - Height(T->Right)) == 2 ) // Violation ! Adjust tree
	{
		if ( IsSmaller(X,T->Left->Element) ) // insertion into left subtree of left child of T
			T = SingleRotateWithLeft(T);
		else  // insertion into right subtree of left child of T
			T = DoubleRotateWithLeft(T);
			
	}
    }
    else if ( IsLarger(X,T->Element) )  // X > T->Element
    {
        T->Right = Insert(T->Right,X);
	// Check if AVL Property has been violated after insertion into right subtree
	if ( (Height(T->Right) - Height(T->Left)) == 2 ) // Violation ! Adjust tree
	{
		if ( IsSmaller(X,T->Right->Element) ) // insertion into left subtree of right child of T
			T = DoubleRotateWithRight(T);
		else  // insertion into right subtree of right child of T
			T = SingleRotateWithRight(T);
	}
    }
    // else X == T->Element ; do nothing
    T->Height = max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

void preorder(AVLTree t){
    if(t==NULL){
        return;
    }
    else{
        printf("%d ",t->Element);
        preorder(t->Left);
        // printf("1\n");
        preorder(t->Right);
        return;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    AVLTree t=NULL;
    for(int i=0;i<n;i++){
        int T;
        scanf("%d",&T);
        t=Insert(t,T);
    }
    // printf("%p \n",t->Left->Right);
    // printf("%d \n",t->Right->Element);
    preorder(t);
}