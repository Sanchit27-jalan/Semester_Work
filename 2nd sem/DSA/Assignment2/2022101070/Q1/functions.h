#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <stdio.h>
#include <stdlib.h>


struct stackinfo
{
    int max_num;
    int top_idx;
    char *stack_element;
};

struct stackinfo *initialize(int max);
int isfull(struct stackinfo *stack);
int isempty(struct stackinfo *stack);
void push(struct stackinfo *stack, char c);
char pop(struct stackinfo *stack);
char top(struct stackinfo *stack);
int balanced(struct stackinfo *stack, int len, char str[]);
int palindrome(struct stackinfo *stack, int len, char str[]);


#endif