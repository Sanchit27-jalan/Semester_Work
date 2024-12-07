#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <stdio.h>
#include <stdlib.h>


typedef struct queue *Queue;
struct node{
    int element;
    struct node* prev;
    struct node* next;
    
};
typedef struct node* node;
struct queue
{
    struct node* front;
    struct node* rear;
    int number;
};

void Push(Queue head, int val);
void Inject(Queue head, int val);
void Print(Queue head);
int Pop(Queue head);
int popRear(Queue head);
void PrintReverse(Queue head);
int findElem(Queue head, int pos);
void removeKElems(Queue head, int k);


#endif