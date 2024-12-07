#include <stdio.h>
#include <stdlib.h>


#ifndef __HASH_H__
#define __HASH_H__


#include <stdio.h>
#include <stdlib.h>

struct elements
{
    int a1;
    int b1;
};
void merge(struct elements *arr, int l, int mid, int r);

void mergesortd(struct elements *arr, int l, int r);

int *journaltwocalc(int*a,int*b,int n);

#endif
