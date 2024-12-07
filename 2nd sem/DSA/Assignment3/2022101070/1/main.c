#include "hash.h"

int main(){
    struct hashtable* myht=malloc(sizeof(struct hashtable));
    myht->tablesize=1000000;
    myht->array=(struct element**)malloc(1000000*sizeof(struct element*));
    for(int i=0;i<1000000;++i){
        myht->array[i]=NULL;
    }
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;++i){
        char s[11];
        scanf("%s",s);
        int t=strlen(s);
        insert(myht,s,t);
    }
    for(int i=0;i<q;++i){
        char s[11];
        scanf("%s",s);
        int len=strlen(s);
        int hash=gethash(s,len);
        int flag=printing(myht,s,len,hash);
        if(flag==0){
            printf("%d",-1);
        }
        printf("\n");
    }
}