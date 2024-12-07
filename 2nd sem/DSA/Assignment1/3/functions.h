#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

typedef struct node* PtrNode;

struct node{
    int element;
    PtrNode next;
};
void Insert(PtrNode Head, int num);

PtrNode Find( PtrNode Head, int num );

void Print( PtrNode Head);



#endif