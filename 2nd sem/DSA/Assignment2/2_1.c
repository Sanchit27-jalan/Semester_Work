#include <stdio.h>
#include <stdlib.h>

typedef struct queue *Queue;
struct node
{
    int element;
    struct node *prev;
    struct node *next;
};
typedef struct node *node;
struct queue
{
    struct node *front;
    struct node *rear;
    int number;
};

void Push(Queue head, int val)
{
    node new = (node)malloc(1 * sizeof(struct node));
    new->element = val;
    if (head->front == NULL)
    {
        head->front = new;
        head->rear = new;
        head->number++;
        new->next = new;
        new->prev = new;
    }
    else
    {
        node temp = head->rear;
        head->rear = new;
        new->prev = temp;
        new->next = head->front;
        head->front->prev = new;
        head->number++;
        temp->next = new;
    }
    return;
}

void Inject(Queue head, int val)
{
    node new = (node)malloc(1 * sizeof(struct node));
    new->element = val;
    if (head->front == NULL)
    {
        head->front = new;
        head->rear = new;
        head->number++;
        new->next = new;
        new->prev = new;
    }
    else
    {
        node temp = head->front;
        head->front = new;
        new->next = temp;
        temp->prev = new;
        head->rear->next = new;
        new->prev = head->rear;
        head->number++;
    }
    return;
}
void Print(Queue head)
{
    node temp = head->front;
    if (temp == NULL)
    {
        printf("%d\n", -1);
    }
    else
    {
        while (temp->next != head->front)
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
    if (head->number == 0)
    {
        return -1;
    }
    else if (head->number == 1)
    {
        int t = head->front->element;
        head->front = NULL;
        head->rear = NULL;
        head->number = 0;
        return (t);
    }
    else
    {
        node temp = head->front;
        head->front = temp->next;
        head->rear->next = head->front;
        head->front->prev = head->rear;
        head->number--;
        return (temp->element);
    }
}
int popRear(Queue head)
{
    if (head->number == 0)
    {
        return -1;
    }
    else if (head->number == 1)
    {
        int t = head->front->element;
        head->front = NULL;
        head->rear = NULL;
        head->number = 0;
        return (t);
    }
    else
    {
        node temp = head->rear;
        head->rear = temp->prev;
        temp->prev->next = head->front;
        head->front->prev = temp->prev;
        head->number--;
        return (temp->element);
    }
    return 0;
}

void PrintReverse(Queue head)
{
    if (head->number == 0)
    {
        printf("%d\n", -1);
    }
    else
    {
        node temp = head->rear;
        while (temp->prev != head->rear)
        {
            printf("%d ", temp->element);
            temp = temp->prev;
        }
        printf("%d \n", temp->element);
    }
}

int findElem(Queue head, int pos)
{
    if (head->number < pos)
    {
        return -1;
    }
    else
    {
        int count = 1;
        node temp = head->front;
        while (count != pos)
        {
            temp = temp->next;
            count++;
        }
        return (temp->element);
    }
}
void removeKElems(Queue head, int k)
{
    if (head->number <= k)
    {
        head->front = NULL;
        head->number = 0;
        head->rear = NULL;
    }
    else
    {
        int count = 1;
        node temp = head->front;
        while (count != k)
        {
            temp = temp->next;
            count++;
        }
        head->rear->next = temp->next;
        temp->next->prev = head->rear;
        head->front = temp->next;
        head->number = head->number - k;
    }
    return;
}
int main()
{
    Queue head = (Queue)malloc(sizeof(struct queue));
    head->front = NULL;
    head->rear = NULL;
    head->number = 0;
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        char str[6];
        scanf("%s", str);
        if (str[4] == '1')
        {
            int n;
            scanf("%d", &n);
            Push(head, n);
        }
        else if (str[4] == '2')
        {
            int t = Pop(head);
            printf("%d\n", t);
        }
        else if (str[4] == '3')
        {
            int n;
            scanf("%d", &n);
            Inject(head, n);
        }
        else if (str[4] == '4')
        {
            int t = popRear(head);
            printf("%d\n", t);
        }
        else if (str[4] == '5')
        {
            Print(head);
        }
        else if (str[4] == '6')
        {
            PrintReverse(head);
        }
        else if (str[4] == '7')
        {
            int n;
            scanf("%d", &n);
            int t = findElem(head, n);
            printf("%d\n", t);
        }
        else if (str[4] == '8')
        {
            int k;
            scanf("%d", &k);
            removeKElems(head, k);
        }
    }
}
