#include <stdio.h>
#include <stdlib.h>

typedef struct queue *Queue;
struct queue
{
    int element;
    Queue next;
    Queue prev;
};
struct dummy
{
    int d;
    Queue head;
};
void Push(Queue head, int val)
{
    if (head->next == NULL)
    {
        head->element = val;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Queue temp = head->prev;
        Queue new = (Queue)malloc(sizeof(struct queue));
        new->element = val;
        new->prev = temp;
        new->next = head;
        temp->next = new;
        head->prev = new;
    }
    return;
}

void Print(Queue head)
{
    if (head->next == NULL)
    {
        printf("%d\n", -1);
    }
    else
    {
        Queue temp = head;
        while (temp->next != head)
        {
            printf("%d ", temp->element);
            temp = temp->next;
        }
        printf("%d \n", temp->element);
    }
    return;
}
int Pop(Queue head)
{
    if (head->element == -1)
    {
        printf("%d \n", -1);
    }
    else if (head->next == head)
    {
        int t = head->element;
        head->element = -1;
        head->next = NULL;
        head->prev = NULL;
        return t;
    }
    else
    {
        Queue temp = head->prev;
        Queue temp2 = head->next;
        Queue to_pop = head;
        int t = to_pop->element;
        temp->next = temp2;
        head->element = -2;
        return t;
    }
    return 0;
}

void Inject(Queue head, int val)
{
    Queue new = (Queue)malloc(sizeof(struct queue));
    new->element = val;
    if(head->next==head){
        head->prev=new;
        new->next=head;
        new->prev=head;
        head->next=new;
    }
    else{
        Queue temp=head->prev;
        temp->next=new;
        new->next=head;
        head->prev=new;
    }
}

int main()
{
    Queue head = (Queue)malloc(sizeof(struct queue));
    head->next = NULL;
    head->prev = NULL;
    head->element = -1;
    struct dummy *dummy = (struct dummy *)malloc(sizeof(struct dummy));
    dummy->head = head;
    dummy->d = 0;
    Push(head, 10);
    Push(head, 20);
    Push(head,30);
    int t = Pop(head);
    printf("%d\n", t);
    if (head->element == -2)
    {
        Queue temp=head;
        head = head->next;
        free(temp);
    }
    Inject(head,5);
    head=head->prev;
    printf("%d\n",head->element);
    printf("%d\n",head->next->element);
    printf("%d\n",head->next->next->element);
    printf("%d\n",head->next->next->next->element);
    // Print(head);
}