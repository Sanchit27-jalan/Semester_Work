#include<stdio.h>
#include<stdlib.h>
typedef struct graph graph;
typedef graph* ptrtograph;
typedef struct node node;
typedef node* ptrtonode;
struct graph{
    int n;
    int a;
    ptrtonode *arr;    

};
struct node{
    int b;
    int c;
    ptrtonode next;

};
typedef struct heap heap;
typedef heap* ptrtoheap;
struct heap{
    int topid;
    int max_elements;
    struct two** arr;
};
struct two{
    int a;
    int b;
    int c;

};


ptrtoheap Createheap(int m){
    ptrtoheap h=(ptrtoheap)malloc(sizeof(heap));
    h->topid=0;
    h->max_elements=m;
    h->arr=(struct two**)malloc(sizeof(struct two*)*(m+1));
        h->arr[0]=(struct two*)malloc(sizeof(struct two));

    
    h->arr[0]->c=-1;

    return h;

}

void Insert1(ptrtoheap * h,int a,int b,int c){
            (*h)->arr[++(*h)->topid]=(struct two*)malloc(sizeof(struct two));

    (*h)->arr[(*h)->topid]->a=a;
     (*h)->arr[(*h)->topid]->b=b;   
         (*h)->arr[(*h)->topid]->c=c;

    int j=(*h)->topid;
    while(j>0){
        if((*h)->arr[j]->c<(*h)->arr[j/2]->c){
            struct two* temp=(*h)->arr[j];
            (*h)->arr[j]=(*h)->arr[j/2];
            (*h)->arr[j/2]=temp;
            j=j/2;
        }
        else{
            return;
        }
    }
    return;

}
struct two* ExtractMin (ptrtoheap * h){
    struct two* min=(*h)->arr[1];

    struct two* temp=(*h)->arr[(*h)->topid--];
    (*h)->arr[1]=temp;
    int i=1;
    int j=(*h)->topid;
    
    int k;

    while(i<j){
        k=2*i;
        if(k>j){
            return min;
        }
        if((*h)->arr[k]->c>(*h)->arr[k+1]->c){
            k++;
        }
        if(k>j){
            return min;
        }
        if((*h)->arr[i]->c>(*h)->arr[k]->c ){
        struct two* temp=(*h)->arr[i];
        (*h)->arr[i]=(*h)->arr[k];
        (*h)->arr[k]=temp;

        }
        i=k;

    }
    return min;

}

ptrtograph creategraph(int n){
    ptrtograph g =(ptrtograph)malloc(sizeof(graph));
    g->n=n;
    g->arr=(ptrtonode*)malloc(sizeof(ptrtonode)*n);
    for(int i=0;i<n;i++){
        g->arr[i]=(ptrtonode)malloc(sizeof(node));
        g->arr[i]->next=NULL;
    }
    return g;

}

void Insert(ptrtograph g,int u,int v,int d){
    ptrtonode t=g->arr[u];
    ptrtonode y=(ptrtonode)malloc(sizeof(node));
    y->b=v;
    y->c=d;
    y->next=t->next;
    t->next=y;
        ptrtonode h=g->arr[v];
    ptrtonode q=(ptrtonode)malloc(sizeof(node));
    q->b=u;
    q->c=d;
    q->next=h->next;
    h->next=q;


}
void Extractall (ptrtoheap h,ptrtograph g,int u){
    ptrtonode t=g->arr[u];
    t=t->next;
    while(t!=NULL){
        Insert1(&h,u,t->b,t->c);
        ptrtonode temp=t;
        t=t->next;
        free(temp);
    }


}
// void createspanningtree(ptrtograph a,ptrtograph b,int m){
    // int *arr=(int*)calloc(a->n,sizeof(int));
    // int c=0;
//     
// Extractall(h,b,1);
// arr[0]=1;
// c++;
//     while(c<a->n){
//         struct two*d=ExtractMin(&h);
//         if(arr[d->b-1]==0){
//             arr[d->b-1]=1;
//             Insert(a,d->a,d->b,d->c);
//             printf("%d %d %d\n",d->a,d->b,d->c);
//             c++;
//             Extractall(h,b,d->b);

//         }
//     }

// }
int find(int * arr,int u){
    if(u==arr[u]){
        return u;
    }
    else{
        arr[u]=find(arr,arr[u]);
        return arr[u];

    }

}
void Union(int *arr,int u,int v){
    int a=find(arr,u);
    int b=find(arr,v);
    if(a!=b){
        arr[b]=a;
    }

}
void createspanningtree(ptrtograph g,int m,int n,ptrtoheap h){
    int *arr=(int*)malloc(g->n*sizeof(int));
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    while(1){
        struct two*d=ExtractMin(&h);
        if(d->c==-1){
            break;
        }
        if(find(arr,d->a)!=find(arr,d->b)){
            Union(arr,d->a,d->b);
            printf("%d %d %d\n",d->a,d->b,d->c);
        } 
        // else if(arr[d->a-1]==0){
        //     arr[d->a-1]=1;
        //                 printf("%d %d %d\n",d->a,d->b,d->c);

        // }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    ptrtograph g=creategraph(n);
    int arr[m];
    int c=0;
    ptrtoheap h=Createheap(m);
    for(int i=0;i<m;i++){
        int a;int b;int c;
     scanf("%d %d %d",&a,&b,&c);
             Insert1(&h,a,b,c);

     
    }
    createspanningtree(g,m,n,h);


}
// 9 14    
// 1 2 4
// 1 8 8
// 2 8 11
// 2 3 8
// 8 9 7
// 8 7 1
// 7 9 6
// 3 9 2
// 3 6 5
// 3 4 7
// 4 6 14
// 4 5 9
// 6 5 10
// 7 6 2