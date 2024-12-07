#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct graph{
    int vertices;
    struct node** table;
};

typedef struct graph* graph;

graph creategraph(int n){
    graph g=malloc(sizeof(struct graph));
    g->vertices=n;
    g->table=(struct node**)malloc(sizeof(struct node*)*(n+1));
    for(int i=0;i<(n+1);++i){
        g->table[i]=(struct node*)malloc(sizeof(struct node));
        g->table[i]->vertex=-1;
        g->table[i]->next=NULL;
    }
    return g;
}

void insertgraph(graph g,int u,int v){
    struct node* new=malloc(sizeof(struct node));
    new->vertex=v;
    new->next=NULL;
    struct node* temp=g->table[u];
    new->next=temp->next;
    temp->next=new;
    return;
}

// int* mst(graph g,int u,int v,int *visited){
//     int *output=malloc(sizeof(int)*2);
//     struct node* ulist=g->table[u];
//     struct node* vlist=g->table[v];
//     int umin=10000;
//     ulist=ulist->next;
//     int vu=0;
//     while(ulist!=NULL){
//         if(visited[ulist->vertex]==0){
//             if(ulist->weight<umin){
//                 umin=ulist->weight;
//                 vu=ulist->vertex;
//             }
//         }
//         ulist=ulist->next;
//     }
//     int vmin=10000;
//     vlist=vlist->next;
//     int uv=0;
//     while(vlist!=NULL){
//         if(visited[vlist->vertex]==0){
//             if(vlist->weight<vmin){
//                 vmin=vlist->weight;
//                 uv=vlist->vertex;
//             }
//         }
//         vlist=vlist->next;
//     }
//     if(umin<=vmin){
//         visited[vu]=1;
//         output[0]=vu;
//         output[1]=v;
//         printf("ans: %d %d \n",u,vu);
//     }
//     else{
//         visited[uv]=1;
//         output[0]=uv;
//         output[1]=u;
//         printf("ans: %d %d \n",v,uv);
//     }
//     return output;
// }
void merge(int *arr,int l,int mid,int r){
    int t=r-l+1;
    int *new=malloc(sizeof(int)*t);
    int j=0;
    int leftsize=mid-l+1;
    int rightsize=r-mid;
    int leftfilled=0;
    int leftindex=l;
    int rightfilled=0;
    int rightindex=mid+1;
    while(j<t){
        if(leftfilled==leftsize){
            new[j]=arr[rightindex];
            j++;
            rightfilled++;
            rightindex++;
        }
        else if(rightfilled==rightsize){
            new[j]=arr[leftindex];
            j++;
            leftfilled++;
            leftindex++;
        }
        else{
            if(arr[leftindex]<arr[rightindex]){
                new[j]=arr[leftindex];
                j++;
                leftfilled++;
                leftindex++;
            }
            else{
                new[j]=arr[rightindex];
                j++;
                rightfilled++;
                rightindex++;
            }
        }
    }
    for(int i=0;i<t;++i){
        arr[l+i]=new[i];
    }
    free(new);
    return;
}
void mergesortd(int *arr,int l,int r){
    if(l>=r){
        return;
    }
    else{
        int mid=(l+r)/2;
        mergesortd(arr,l,mid);
        mergesortd(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void dfs(graph g,int *visited,int f){
    if(visited[f]==0){
        printf("%d ",f);
        struct node* flist=g->table[f]->next;
        visited[f]=1;
        // int *array=malloc(sizeof(int)*100);
        // int len=0;
        while(flist!=NULL){
            // array[len]=flist->vertex;
            // len++;
            dfs(g,visited,flist->vertex);
            flist=flist->next;
        }
        // mergesortd(array,0,len-1);
        // for(int i=0;i<len;i++){
        //     dfs(g,visited,array[i]);
        // }
    }
    return;
}

int main(){
    int n,m;
    // n=5;
    // m=5;
    scanf("%d %d",&n,&m);
    graph g=creategraph(n);
    // int minw=10000;
    // int vmin=0;
    // int umin=0;
    int u,v;
    for(int i=0;i<m;++i){
        scanf("%d %d",&u,&v);
        insertgraph(g,u,v);
        insertgraph(g,v,u);
        // if(w<minw){
        //     minw=w;
        //     vmin=v;
        //     umin=u;
        // }
    }
    int *pushed=malloc(sizeof(int)*(n+1));
    for(int i=0;i<=n;i++){
        pushed[i]=0;
    }
    for(int i=1;i<=n;i++){
        dfs(g,pushed,i);
    }
    // for(int i=1;i<n+1;i++){
    //     if(pushed[i]==0){
    //         printf("%d ",i);
    //     }
    // }
    // printf("\n");
    // pushed[umin]=1;
    // pushed[vmin]=1;
    // printf("ans: %d %d\n",umin,vmin);
    // for(int i=0;i<n-2;i++){
    //     int *ans=mst(g,umin,vmin,pushed);
    //     umin=ans[0];
    //     vmin=ans[1];
    //     printf("Next Traversal is %d %d\n",umin,vmin);
    //     free(ans);
    // }
}