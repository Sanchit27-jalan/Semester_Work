#include <stdio.h>
#include <stdlib.h>


#ifndef __HASH_H__
#define __HASH_H__


#include <stdio.h>
#include <stdlib.h>

int insertion(char *one, char *two, int one_l, int two_l);
void merge(char **strarray, int l, int mid, int r, int *arr ,int n, int maxlength);
void mergesortd(char **strarray, int l, int r, int *arr ,int n, int maxlength);


#endif
