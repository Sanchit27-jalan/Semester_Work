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
int deleting_min_element(heap h);


#endif