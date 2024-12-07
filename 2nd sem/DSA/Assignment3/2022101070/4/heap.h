#include <stdio.h>
#include <stdlib.h>

#ifndef __HEAP_H__
#define __HEAP_H__

struct stheap
{
    int size;
    int capacity;
    int *elements;
};

typedef struct stheap *heap;
heap create(int cap);
void insert(heap h, int n);
void extracting_max_to_last(heap h);


#endif