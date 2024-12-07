#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int t;
    scanf("%d", &t);
    char l[6];
    for (int i = 0; i < t; ++i)
    {
        scanf("%s", l);
        if (l[4] == '1')
        {
            int l1, l2;
            scanf("%d %d", &l1, &l2);
            int arr1[l1];
            int arr2[l2];
            for (int j = 0; j < l1; ++j)
            {
                scanf("%d", &arr1[j]);
            }
            for (int j = 0; j < l2; ++j)
            {
                scanf("%d", &arr2[j]);
            }
            int *a = intersectionArray(arr1, arr2, l1, l2);
            if (a[0] != 0)
            {
                for (int j = 1; j <= a[0]; ++j)
                {
                    printf("%d ", a[j]);
                }
                printf("\n");
            }
        }
        else if (l[4] == '2')
        {
            int n;
            scanf("%d \n", &n);
            char arr1[n + 1];
            scanf("%s \n", arr1);
            char ch;
            scanf("%c", &ch);
            int a = countCharOccurrences(arr1, n, ch);
            printf("%d \n", a);
        }
        else if (l[4] == '3')
        {
            int n;
            scanf("%d", &n);
            char arr1[n + 1];
            scanf("%s", arr1);
            char h = findFirstNonRepeatingChar(arr1, n);
            if (h != '\0')
            {
                printf("%c \n", h);
            }
        }
        else if (l[4] == '4')
        {
            int n;
            scanf("%d",&n);
            char **str;
            str = (char **)calloc(n, sizeof(char *));
            for (int i = 0; i < n; ++i)
            {
                str[i] = (char *)calloc(101, sizeof(char));
            }
            int maxLen=0;
            int t;
            for (int i = 0; i < n; ++i)
            {
                char arr[101];
                scanf("%d %s",&t,arr);
                for(int j=0;j<t;++j){
                    str[i][j]=arr[j];
                }
                if (t>maxLen){
                    maxLen=t;
                }
            }
            char *a;
            a = findLongestCommonPrefix(str, n, maxLen);
            if(a[0]!='\0'){
                printf("%s\n",a);
            }
            else{
                printf("%d\n",-1);
            }
        }
        else if (l[4] == '5')
        {
            int n;
            scanf("%d", &n);
            int arr1[n];
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &arr1[j]);
            }
            int *a = maxMin(arr1, n);
            if (a[0] == 0)
            {
                printf("%d \n", -1);
            }
            else
            {
                for (int j = 1; j < a[0] + 1; ++j)
                {
                    printf("%d ", a[j]);
                }
                printf("\n");
            }
        }
        else
        {
            int m, n;
            scanf("%d %d", &m, &n);
            char str[m + 1];
            char str2[n + 1];
            scanf("%s", str);
            scanf("%s", str2);
            char *ch;
            ch = removeSubstring(str, m, str2, n);
            if (ch[0] != '\0')
            {
                printf("%s \n", ch);
            }
            else
            {
                printf("%d \n", -1);
            }
        }
    }
}