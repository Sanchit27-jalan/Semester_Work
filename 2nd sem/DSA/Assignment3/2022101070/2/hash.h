#include <stdio.h>
#include <stdlib.h>
#define p 31
#define mod 1000000007

#ifndef __HASH_H__
#define __HASH_H__

long long int *array_maker(char *str, int len);
char *reverse(char *str, int len);
long long int *prime_array(int len);
int checker(int l, int r, long long int *front, long long int *back, int n, long long int *prime);
#endif