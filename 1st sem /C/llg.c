#include "linked_list.h"

LinkedList create_empty_linked_list() {
    return NULL;
}

LinkedList append(Customer* c, LinkedList l) {

    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = c;
    n->next = NULL;

    struct Node* i = l;

    if (i == NULL) {
        return n;
    } else {
        while(i->next != NULL) {
            i = i->next;
        }
        i->next = n;
        return l;
    }
    
}

Customer* element_at(int i, LinkedList l) {
    while(i >0) {
        l = l->next;
        i--;
    }
    return l->data;
}

void print_list(LinkedList l) {
    while(l != NULL) {
        printf("%s\t%d\n", l->data->name, l->data->phone_no);
        l = l->next;
    }
}
LinkedList delete(int n,LinkedList l){
    LinkedList cur = l;
    if(n==0){
        l=l->next;
        return l;
    }
    else{
        n--;
        while (n>0){
            cur=cur->next;
            n--;
        }
        cur->next=cur->next->next;
        return l;
    }
}
int main(){
    LinkedList l= create_empty_linked_list();
    Customer c;
    strcpy(c.name,"Sanchit");
    c.phone_no=98;
    l=append(&c,l);
    Customer c2;
    strcpy(c2.name,"Sujal");
    c2.phone_no=81;
    l=append(&c2,l);
    Customer c3;
    strcpy(c3.name,"Sumit");
    c3.phone_no=93;
    l=append(&c3,l);
    // Customer *c3=element_at(0,l);
    // printf("%s \n",c3->name);
    // printf("%d \n",c3->phone_no);
    //print_list(l);
    l=delete(0,l);
    print_list(l);
}