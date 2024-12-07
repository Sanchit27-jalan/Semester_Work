#include <stdio.h>
#include <stdlib.h>


#ifndef __HASH_H__
#define __HASH_H__


struct stheap
{
    int size;
    int capacity;
    int *elements;
};

typedef struct stheap *heap;

heap create(int cap);

void insert(heap h, int n);

int changing_max_element(heap h);

long long int happy_calc(heap h,int k);

#endif
