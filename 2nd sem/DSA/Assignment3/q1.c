#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct element{
    char str[11];
    struct element* next;
};

struct hashtable{
    int tablesize;
    struct element** array;
};

int gethash(char arr[],int len){
    int sum=0;
    for(int i=0;i<len;++i){
        int d=(int)arr[i]-(int)'a';
        d=d*d*d*d;
        sum=sum+d;
    }
    sum=sum%1000000;
    return sum;
}


void insert(struct hashtable* myht,char arr[],int len){
    int key=gethash(arr,len);
    if(myht->array[key]==NULL){
        struct element* new=malloc(sizeof(struct element));
        new->next=NULL;
        for(int i=0;i<len;++i){
            new->str[i]=arr[i];
        }
        myht->array[key]=new;
        return;
    }
    else{
        struct element* new=malloc(sizeof(struct element));
        new->next=NULL;
        for(int i=0;i<len;++i){
            new->str[i]=arr[i];
        }
        struct element* temp=myht->array[key];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}

int anagram_checker(char arr[],char arr2[],int len1,int len2){
    if(len1!=len2){
        return 0;
    }
    int freq[27]={0};
    for (int i=0;i<len1;++i){
        int d=(int)arr[i]-(int)'a';
        freq[d]++;
    }
    for(int i=0;i<len2;++i){
        int d=(int)arr2[i]-(int)'a';
        freq[d]--;
    }
    for(int i=0;i<27;++i){
        if(freq[i]!=0){
            return 0;
        }
    }
    return 1;
}

int printing(struct hashtable* myht,char query[],int len_q,int key){
    int count=0;
    struct element* temp=myht->array[key];
    while(temp!=NULL){
        char str[11];
        char str2[11];
        int len=0;
        for(int i=0;temp->str[i]!='\0';++i){
            str[i]=temp->str[i];
            str2[i]=temp->str[i];
            len++;
        }
        str[len]='\0';
        str2[len]='\0';
        char query2[11];
        for(int i=0;i<len_q;++i){
            query2[i]=query[i];
        }
        query2[len_q]='\0';
        int checker=anagram_checker(str,query2,len,len_q);
        if(checker==1){
            printf("%s ",str2);
            count++;
        }
        temp=temp->next;
    }
    return count;
}


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