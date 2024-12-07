#include "functions.h"


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