#include "functions.h"

int countCharOccurrences(const char *str, int length, char ch)
{
    int ct = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str[i] == ch)
        {
            ct++;
        }
    }
    return (ct);
}

char findFirstNonRepeatingChar(const char *str, int length)
{
    char ch;
    int check = 1;
    for (int i = 0; i < length; ++i)
    {
        ch = str[i];
        int flag = 1;
        for (int j = 0; j < length; ++j)
        {
            if (str[j] == ch && i != j)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            check = 0;
            return (ch);
        }
    }
    if (check == 1)
    {
        printf("%d \n", -1);
        return (0);
    }
    return (0);
}

char *removeSubstring(char *str, int strLength, const char *substr, int substrLength)
{

    char *ch = (char *)(calloc((strLength + 1), sizeof(char)));

    int i = 0;
    int t = 0;
    int j = 0;
    while (i < strLength)
    {
        for (j = 0; j < substrLength; ++j)
        {
            if (str[i + j] == substr[j])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j != (substrLength))
        {
            ch[t] = str[i];
            i++;
            t++;
        }
        else
        {
            i = i + substrLength;
        }
    }
    return ch;
}

int *maxMin(int *arr, int lenArr)
{
    int ct = 0;
    int *index;
    index = (int *)malloc((ct + 1) * sizeof(int));
    index[0] = ct;
    int max = -1;
    int min = 10000000;
    for (int i = 0; i < lenArr; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    if (arr[0] == min)
    {
        ct++;
        index = (int *)realloc(index, (ct + 1) * sizeof(int));
        index[0] = ct;
        index[ct] = 0;
    }
    int left = arr[0];
    int right = arr[lenArr - 1];
    int *freq = calloc(lenArr - 2, sizeof(int));
    for (int i = 1; i < lenArr - 1; ++i)
    {
        if (arr[i] > left)
        {
            freq[i - 1] = freq[i - 1] + 1;
            left = arr[i];
        }
    }
    for (int i = lenArr - 1; i > 0; --i)
    {
        if (arr[i] < right)
        {
            freq[i - 1] = freq[i - 1] + 1;
            right = arr[i];
        }
    }
    for (int i = 0; i < lenArr - 2; ++i)
    {
        if (freq[i] == 2)
        {
            ct++;
            index = (int *)realloc(index, (ct + 1) * sizeof(int));
            index[0] = ct;
            index[ct] = i+1;;
        }
    }
    if (arr[lenArr - 1] == max)
    {
        ct++;
        index = (int *)realloc(index, (ct + 1) * sizeof(int));
        index[0] = ct;
        index[ct] = lenArr - 1;
    }
    return (index);
}

int *intersectionArray(int *arr1, int *arr2, int lenArr1, int lenArr2)
{
    int max1, max2;
    max1 = 0;
    max2 = 0;
    for (int i = 0; i < lenArr1; ++i)
    {
        if (arr1[i] >= max1)
        {
            max1 = arr1[i];
        }
    }
    for (int j = 0; j < lenArr2; ++j)
    {
        if (arr2[j] >= max2)
        {
            max2 = arr2[j];
        }
    }
    int *a1;
    int *a2;
    a1 = (int *)calloc(max1 + 1, sizeof(int));
    a2 = (int *)calloc(max2 + 1, sizeof(int));
    for (int i = 0; i < lenArr1; ++i)
    {
        a1[arr1[i]]++;
    }
    for (int i = 0; i < lenArr2; ++i)
    {
        a2[arr2[i]]++;
    }
    int t;
    if (max1 > max2)
    {
        t = max2;
    }
    else
    {
        t = max1;
    }
    int unct = 0;
    int *ret;
    ret = (int *)malloc((10001) * sizeof(int));
    for (int k = 0; k <= t; ++k)
    {
        if (a1[k] != 0 && a2[k] != 0)
        {
            // ret[0]=unct;
            int m;
            if (a1[k] > a2[k])
            {
                m = a2[k];
            }
            else
            {
                m = a1[k];
            }
            // printf("%d \n",m);
            for (int i = 0; i < m; ++i)
            {
                unct++;
                ret[unct] = k;
                // printf("%d \n",k);
            }
            ret[0] = unct;
        }
    }
    int *re;
    re = (int *)malloc((unct + 1) * sizeof(int));
    re[0] = unct;
    for (int i = 1; i <= unct; ++i)
    {
        re[i] = ret[i];
    }
    if (unct == 0)
    {
        printf("%d \n", -1);
    }
    free(ret);
    free(a1);
    free(a2);
    return (re);
}

char *findLongestCommonPrefix(char **str, int numStr, int maxLen)
{
    char *ch;
    int t = 0;
    int ct = 0;
    ch = (char *)calloc(101, sizeof(char));
    for (int i = 0; i < maxLen; ++i)
    {
        for (int j = 0; j < numStr - 1; ++j)
        {
            if (str[j + 1][i] == str[j][i])
            {
                t++;
            }
        }
        if (t == (numStr - 1))
        {
            ch[ct] = str[0][i];
            t = 0;
            ct++;
        }
        else
        {
            break;
        }
    }
    return (ch);
}
