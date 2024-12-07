#include <stdio.h>
#include <stdlib.h>

struct node {
    int c;
    struct node *link;
};

void appending(struct node *head) {
    struct node *ptr = head;
    while (ptr->link!= NULL) { //ptr!=NULL;
        ptr = ptr->link;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int a;
    printf("Enter value: ");
    scanf("%d", &a);
    new_node->c = a;
    new_node->link = NULL;
    ptr->link = new_node;
}
struct node* reversal(struct node* head){
    struct node* prev=NULL;
    struct node* next;
    struct node* tochange=head->link;
    next=tochange->link;
    while(tochange!=NULL){
        tochange->link=prev;
        prev=tochange;
        tochange=next;
        if(next!=NULL){
            next=next->link;
        }
    }
    head->link=prev;
    return(head);
}
void printing(struct node* head){
    struct node* temp=head->link;
    while(temp!=NULL){
        printf("%d ",temp->c);
        temp=temp->link;
    }
    printf("\n");
    return;
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->c = 10;
    head->link = NULL;
    int t;
    while(1){
        scanf("%d",&t);
        if(t==1){
            appending(head);
        }
        else if(t==2){
            head=reversal(head);
        }
        else if(t==3){
            printing(head);
        }
        else{
            break;
        }
    }
}