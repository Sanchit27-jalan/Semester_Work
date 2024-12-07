#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stheap{
    int size;
    int capacity;
    int* elements;
};

typedef struct stheap* heap;
heap create(int cap){
    heap h;
    h=malloc(sizeof(struct stheap));
    h->size=0;
    h->capacity=cap;
    h->elements=(int *)malloc(sizeof(int)*cap);
    return h;
}
void insert(heap h,int n){
    if(h->size==0){
        h->size++;
        h->elements[1]=n;
    }
    else{
        int t=h->size;
        h->elements[t+1]=n;
        for(int i=t+1;i>1;i=i/2){
            if(h->elements[i]>=h->elements[i/2]){
                break;
            }
            else{
                int temp=h->elements[i];
                h->elements[i]=h->elements[i/2];
                h->elements[i/2]=temp;
            }
        }
        h->size++;
    }
    return ;
}


int delete(heap h){
    int n=h->elements[1];
    int x=h->elements[h->size];
    h->elements[1]=x;
    int i = 1;
    while (i * 2 <= h->size) {
        int j = i * 2;
        if (j + 1 <= h->size && h->elements[j + 1] < h->elements[j]) {
            j++;
        }
        if (h->elements[j] >= h->elements[i]) {
            break;
        }
        int temp = h->elements[i];
        h->elements[i] = h->elements[j];
        h->elements[j] = temp;
        i = j;
    }
    h->size--;
    return n;
}

int main(){
    heap h=create(100);
    insert(h,5);
    insert(h,10);
    insert(h,15);
    insert(h,20);
    insert(h,25);
    insert(h,12);
    insert(h,1);
    for(int i=1;i<8;++i){
        printf("%d ",h->elements[i]);
    }
    printf("\n");
    int t=delete(h);
    t=delete(h);
    t=delete(h);
    for(int i=1;i<h->size+1;++i){
        printf("%d ",h->elements[i]);
    }
    printf("\n");
}