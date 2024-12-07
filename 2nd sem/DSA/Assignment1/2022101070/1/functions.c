#include "functions.h"

void reverseString(char *str, int length)
{
    for (int i = 0; i < (length / 2); ++i)
    {
        char c;
        c = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = c;
    }
    printf("%s \n", str);
}

int *uniqueElements(int *arr, int length)
{
    int *s;
    int unct = 0;
    int *dp = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; ++i)
    {
        if (dp[arr[i]] == 0)
        {
            dp[arr[i]] = 1;
            unct++;
        }
    }
    s = (int *)(malloc((unct + 1) * sizeof(int)));
    s[0] = unct;
    int j = 1;
    for (int i = 0; i < length; ++i)
    {
        if (dp[arr[i]] == 1)
        {
            s[j] = arr[i];
            dp[arr[i]] = 0;
            j++;
        }
    }
    free(dp);
    return (s);
}

char *compressString(char *str, int length)
{
    char *c = (char *)(calloc((2 * length + 5), sizeof(char)));
    int ct = 0;
    int uni = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str[i] == str[i + 1])
        {
            ct++;
        }
        else
        {
            c[uni] = str[i];
            ct++;
            int temp = ct;
            int no = 0;
            while (temp > 0)
            {
                no++;
                temp = temp / 10;
            }
            int j = no - 1;
            while (ct > 0)
            {
                c[uni + 1 + j] = (ct % 10) + 48;
                ct = ct / 10;
                j--;
            }
            uni = uni + no;
            uni++;
            ct = 0;
        }
    }
    return c;
}

int **transpose(int **matrix, int NumRow, int NumCol)
{
    int **arr;
    arr = (int **)calloc(NumCol, sizeof(int *));
    for (int i = 0; i < NumCol; ++i)
    {
        arr[i] = (int *)calloc(NumRow, sizeof(int));
    }
    for (int i = 0; i < NumRow; ++i)
    {
        for (int j = 0; j < NumCol; ++j)
        {
            arr[j][i] = matrix[i][j];
        }
    }
    return (arr);
}