#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef __HASH_H__
#define __HASH_H__

struct element{
    char str[11];
    struct element* next;
};

struct hashtable{
    int tablesize;
    struct element** array;
};

int gethash(char arr[],int len);

void insert(struct hashtable* myht,char arr[],int len);

int anagram_checker(char arr[],char arr2[],int len1,int len2);

int printing(struct hashtable* myht,char query[],int len_q,int key);


#endif