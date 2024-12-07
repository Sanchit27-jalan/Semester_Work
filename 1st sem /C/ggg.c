#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *add(int n,struct node *head){
    struct node *q= (struct node*)malloc(sizeof(struct node));
    q->data=n;
    q->next=NULL;
    struct node *i=head;
    if (i==NULL){
        return q;
    }
    else{
        while(i->next!=NULL){
            i=i->next;
        }
        i->next=q;
        return head;
    }
}
void printing(struct node *head){
    while(head!=NULL){
        printf("%d \n",head->data);
        head=head->next;
    }
}
struct node *delete(int n,struct node *head){
    if (n==0){
        head=head->next;
        return head;
    }
    else{
        struct node *temp=head;
        while(n>1){
            temp=temp->next;
            n--;
        }
        temp->next=temp->next->next;
        return head;
    }
}
void element(int n,struct node *head){
    /*if(n==0){
        printf("%d \n",head->data);
        return;
    }*/
        while(n>0){
            head=head->next;
            n--;
        }
        printf("%d \n",head->data);
        return;
}
int main(){
    struct node *d=NULL;
    d=add(2,d);
    d=add(3,d);
    d=add(4,d);
    printing(d);
    d=delete(0,d);
    printing(d);
    element(0,d);
    element(1,d);
    d=add(4,d);
}
