#include <stdio.h>
#include <stdlib.h>

struct node
{
    int a;
    struct node *next;
};
struct node *addlist(int n, struct node *head)
{
    for (int i = 0; i < n; ++i)
    {
        struct node *b;
        b = malloc(sizeof(struct node));
        int c;
        printf("Enter integer:");
        scanf("%d", &c);
        b->a = c;
        b->next = NULL;
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = b;
    }
    return head;
}
void printing(struct node *head){
    while(head->next!=NULL){
        printf("%d\n",head->a);
        head=head->next;
    }
    printf("%d \n",head->a);
}
struct node *delete(int n,struct node *head){
   // n--;
   // n--;
    while (n>2){
        head=head->next;
        n--;
    }
    head->next=head->next->next;
    return head;
}
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    //head = NULL;
    head->next = NULL;
    head->a = 1;
    /*printf("%d \n", head->a);*/
    addlist(5, head);
    printing(head);
    delete(3,head);
    printing(head);
}