#include <stdio.h>
#include <stdlib.h>

typedef struct node* PtrNode;

struct node{
    int element;
    PtrNode next;
};

void Insert(PtrNode Head, int num)
{
    PtrNode temp = Head;
    if (temp->next == NULL)
    {
        PtrNode c = (struct node *)malloc(sizeof(struct node));
        c->element = num;
        c->next = c;
        Head->next = c;
        return;
    }
    PtrNode temp2 = Head->next;
    PtrNode c = (struct node *)malloc(sizeof(struct node));
    c->element = num;
    c->next = temp2;
    temp = Head->next;
    while (temp->next != temp2)
    {
        temp = temp->next;
    }
    temp->next = c;
    Head->next = c;
    return;
}

PtrNode Find(PtrNode Head, int num)
{
    if (Head->next == NULL)
    {
        return NULL;
    }
    if (Head->next->next == Head->next)
    {
        if (Head->next->element==num){
            return Head;
        }
        else{
            return NULL;
        }
    }
    if (Head->next->next->next == Head->next)
    {
        if(Head->next->element==num){
            return(Head->next);
        }
        else if(Head->next->next->element==num){
            PtrNode temp=Head->next;
            PtrNode temp1=Head->next->next;
            Head->next=temp1;
            temp1->next=temp;
            temp->next=temp1;
            return(temp1);
        }
        else{
            return NULL;
        }
    }
    if (Head->next->next->next->next == Head->next){
        if(Head->next->element==num){
            return(Head->next);
        }
        else if(Head->next->next->element==num){
                PtrNode temp=Head->next->next;
                PtrNode temp1=Head->next;
                PtrNode temp2=Head->next->next->next;
                Head->next=temp;
                temp->next=temp1;
                temp1->next=temp2;
                temp2->next=temp;
                return(temp);
        }
        else if(Head->next->next->next->element==num){
            PtrNode temp2=Head->next->next->next;
            Head->next=temp2;
            return(temp2);
        }
        else{
            return NULL;
        }
    }
    if(Head->next->element==num){
        return Head->next;
    }
    PtrNode temp_tochange = Head->next;
    PtrNode last_node = Head->next;
    PtrNode f = last_node;
    while (last_node->next != f)
    {
        last_node = last_node->next;
    }
    while (temp_tochange->element != num)
    {
        if(temp_tochange==last_node){
            break;
        }
        temp_tochange = temp_tochange->next;
    }
    if(last_node==temp_tochange && temp_tochange->element==num){
        Head->next=last_node;
        return(last_node);
    }
    else if(last_node==temp_tochange && temp_tochange->element!=num){
        return NULL;
    }
    PtrNode head_next_storage = Head->next;
    PtrNode node_after_tochange = temp_tochange->next;
    PtrNode node_before_tochange = Head->next;
    while (node_before_tochange->next != temp_tochange)
    {
        node_before_tochange = node_before_tochange->next;
    }
    Head->next = temp_tochange;
    temp_tochange->next = head_next_storage;
    node_before_tochange->next = node_after_tochange;
    last_node->next = temp_tochange;
    return (temp_tochange);
}

void Print(PtrNode Head)
{
    PtrNode temp = Head;
    if (temp->next == NULL)
    {
        return;
    }
    temp = temp->next;
    PtrNode temp2;
    temp2 = Head->next;
    while (temp->next != temp2)
    {
        printf("%d ", temp->element);
        temp = temp->next;
    }
    printf("%d \n", temp->element);
    return;
}

int main(){
    PtrNode head;
    head=(struct node*)malloc(sizeof(struct node));
    head->element=1;
    head->next=NULL;
    int t;
    scanf("%d",&t);
    char arr[6];
    for(int i=0;i<t;++i){
        scanf("%s",arr);
        if(arr[4]=='1'){
            int n;
            scanf("%d",&n);
            Insert(head,n);
        }
        else if(arr[4]=='2'){
            int n;
            scanf("%d",&n);
            PtrNode f=Find(head,n);
        }
        else if(arr[4]=='3'){
            Print(head);
        }
    }
}