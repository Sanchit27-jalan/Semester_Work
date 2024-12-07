#include <stdio.h>
#include <stdlib.h>
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

struct node
{
    int row;
    int col;
    int value;
    struct node *next;
};
struct node *transpose(struct node *dummy, int k);

void add(struct node* dummy1,struct node* dummy2);

void merge(int arr[][3], int left[][3], int right[][3], int left_size, int right_size);

void merge_sort(int arr[][3], int n);

void multiply_2(struct node *dummy1, struct node *dummy2);


#endif