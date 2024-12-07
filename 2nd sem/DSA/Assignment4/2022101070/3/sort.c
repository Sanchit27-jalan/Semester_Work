#include "sort.h"

int insertion(char *one, char *two, int one_l, int two_l)
{
    int min = one_l;
    if (min > two_l)
    {
        min = two_l;
    }
    int i;
    for (i = 0; i < min; ++i)
    {
        if (one[i] > two[i])
        {
            if (i % 2 == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (one[i] < two[i])
        {
            if (i % 2 == 1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            continue;
        }
    }
    if (i == min)
    {
        if (min % 2 == 0)
        {
            if (one_l > two_l)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (one_l > two_l)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 1;
}
void merge(char **strarray, int l, int mid, int r, int *arr ,int n, int maxlength)
{
    int t = r - l + 1;
    int *new = malloc(sizeof(int) * t);
    char **strnew = (char **)malloc(t * sizeof(char *));
    for (int i = 0; i < t; ++i)
    {
        strnew[i] = (char *)malloc(sizeof(char) * maxlength);
    }
    int j = 0;
    int leftsize = mid - l + 1;
    int rightsize = r - mid;
    int leftfilled = 0;
    int leftindex = l;
    int rightfilled = 0;
    int rightindex = mid + 1;
    while (j < t)
    {
        if (leftfilled == leftsize)
        {
            new[j] = arr[rightindex];
            int i;
            for (i = 0; i < new[j]; ++i)
            {
                strnew[j][i] = strarray[rightindex][i];
            }
            strnew[j][i] = '\0';
            j++;
            rightfilled++;
            rightindex++;
        }
        else if (rightfilled == rightsize)
        {
            new[j] = arr[leftindex];
            int i;
            for (i = 0; i < new[j]; ++i)
            {
                strnew[j][i] = strarray[leftindex][i];
            }
            strnew[j][i] = '\0';
            j++;
            leftfilled++;
            leftindex++;
        }
        else
        {
            int value = insertion(strarray[leftindex], strarray[rightindex], arr[leftindex], arr[rightindex]);
            if (value==1)
            {
                new[j] = arr[leftindex];
                int i;
                for (i = 0; i < new[j]; ++i)
                {
                    strnew[j][i] = strarray[leftindex][i];
                }
                strnew[j][i] = '\0';
                j++;
                leftfilled++;
                leftindex++;
            }
            else
            {
                new[j] = arr[rightindex];
                int i;
                for (i = 0; i < new[j]; ++i)
                {
                    strnew[j][i] = strarray[rightindex][i];
                }
                strnew[j][i] = '\0';
                j++;
                rightfilled++;
                rightindex++;
            }
        }
    }

    for (int i = 0; i < t; ++i)
    {
        arr[l + i] = new[i];
        int j;
        for (j = 0; j < new[i]; ++j)
        {
            strarray[l + i][j] = strnew[i][j];
        }
        strarray[l + i][j] = '\0';
    }
    for (int i = 0; i < t; ++i)
    {
        free(strnew[i]);
    }
    free(strnew);
    free(new);
    return;
}
void mergesortd(char **strarray, int l, int r, int *arr ,int n, int maxlength)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        mergesortd(strarray, l, mid, arr,n, maxlength);
        mergesortd(strarray, mid + 1, r, arr,n, maxlength);
        merge(strarray, l, mid, r, arr, n, maxlength);
    }
}