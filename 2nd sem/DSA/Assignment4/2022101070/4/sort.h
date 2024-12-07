#include <stdio.h>
#include <stdlib.h>


#ifndef __HASH_H__
#define __HASH_H__


#include <stdio.h>
#include <stdlib.h>

int *max_array(int **student, int k, int m, int schoolno);

void merge(int *arr, int l, int mid, int r);

void mergesortd(int *arr, int l, int r);

int *sortedschool(int **student, int m, int schoolno);

int countcalc(int *sorted, int *max_array, int k, int m);


#endif
