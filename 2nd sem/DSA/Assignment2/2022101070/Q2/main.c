#include "functions.h"

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
