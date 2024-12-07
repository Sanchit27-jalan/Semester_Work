#include "functions.h"

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        char str[10010];
        scanf("%s", str);
        int len = 0;
        for (int j = 0; j < 10010; ++j)
        {
            if (str[j] == '\0')
            {
                break;
            }
            else
            {
                len++;
            }
        }
        struct stackinfo *stack = initialize(10010);
        int flag_balanced = balanced(stack, len, str);
        struct stackinfo *stack1=initialize(10010);
        int flag_palindrome=palindrome(stack1,len,str);
        if(flag_palindrome==1){
            printf("Palindromic\n");
        }
        else if(flag_balanced==1){
            printf("Balanced\n");
        }
        else if(flag_balanced==0 && flag_palindrome==0){
            printf("%d\n",-1);
        }
    }
}