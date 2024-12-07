#include "functions.h"


struct stackinfo *initialize(int max)
{
    struct stackinfo *stack;
    stack = (struct stackinfo *)malloc(sizeof(struct stackinfo));
    stack->max_num = max;
    stack->top_idx = -1;
    stack->stack_element = (char *)malloc(sizeof(char) * max);
    return (stack);
}

int isfull(struct stackinfo *stack)
{
    int t = stack->top_idx;
    int y = stack->max_num;
    if (y == (t + 1))
    {
        return 0;
    }
    return 1;
}

int isempty(struct stackinfo *stack)
{
    if (stack->top_idx == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stackinfo *stack, char c)
{
    if (isfull(stack) == 0)
    {
        return;
    }
    else
    {
        stack->stack_element[++stack->top_idx] = c;
        return;
    }
}
char pop(struct stackinfo *stack)
{
    if (isempty(stack) == 1)
    {
        return '\0';
    }
    else
    {
        char p = stack->stack_element[stack->top_idx];
        stack->stack_element[stack->top_idx] = '\0';
        stack->top_idx--;
        return p;
    }
}
char top(struct stackinfo *stack)
{
    if (isempty(stack) == 1)
    {
        return '\0';
    }
    else
    {
        char p = stack->stack_element[stack->top_idx];
        return p;
    }
}

int balanced(struct stackinfo *stack, int len, char str[])
{
    int flag=1;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(stack, str[i]);
            flag=2;
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            char c = pop(stack);
            if (str[i] == ')')
            {
                if (c == '(')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            if (str[i] == ']')
            {
                if (c == '[')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            if (str[i] == '}')
            {
                if (c == '{')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    if (isempty(stack) == 1)
    {
        if(flag==2){
            return 1;
        }
        else{
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int palindrome(struct stackinfo *stack, int len, char str[]){
    int y;
    if(len%2==0){
        y=len/2;
    }
    else{
        y=len/2+1;
    }
    for(int i=0;i<len/2;++i){
        push(stack,str[i]);
    }
    for(int i=y;i<len;++i){
        char c=pop(stack);
        if(c!=str[i]){
            return 0;
        }
    }
    if(isempty(stack)==1){
        return 1;
    }
    else{
        return 0;
    }
}