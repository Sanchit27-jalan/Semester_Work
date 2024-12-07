#include <stdio.h>
#include <stdlib.h>
int *max_array(int **student, int k, int m, int schoolno)
{
    int *arr = malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i)
    {
        int max = -1;
        for (int j = 0; j < k; ++j)
        {
            if (j == (schoolno - 1))
            {
                continue;
            }
            else
            {
                if (max < student[j][i])
                {
                    max = student[j][i];
                }
            }
        }
        arr[i] = max;
    }
    return arr;
}
void merge(int *arr, int l, int mid, int r)
{
    int t = r - l + 1;
    int *new = malloc(sizeof(int) * t);
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
            j++;
            rightfilled++;
            rightindex++;
        }
        else if (rightfilled == rightsize)
        {
            new[j] = arr[leftindex];
            j++;
            leftfilled++;
            leftindex++;
        }
        else
        {
            if (arr[leftindex] < arr[rightindex])
            {
                new[j] = arr[leftindex];
                j++;
                leftfilled++;
                leftindex++;
            }
            else
            {
                new[j] = arr[rightindex];
                j++;
                rightfilled++;
                rightindex++;
            }
        }
    }
    for (int i = 0; i < t; ++i)
    {
        arr[l + i] = new[i];
    }
    free(new);
    return;
}
void mergesortd(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        mergesortd(arr, l, mid);
        mergesortd(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int *sortedschool(int **student, int m, int schoolno)
{
    int *sorted = malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i)
    {
        sorted[i] = student[schoolno - 1][i];
    }
    mergesortd(sorted, 0, m - 1);
    return sorted;
}
int countcalc(int *sorted, int *max_array, int k, int m)
{
    int count = 0;
    // for (int i = 0; i < m; ++i)
    // {
    //     int val = max_array[i];
    //     int j = 0;
    //     for (j = 0; j < m; ++j)
    //     {
    //         if (sorted[j] == -1)
    //         {
    //             continue;
    //         }
    //         if (sorted[j] > val)
    //         {
    //             sorted[j] = -1;
    //             break;
    //         }
    //     }
    //     if (j != m)
    //     {
    //         count++;
    //     }
    //     if (j == m)
    //     {
    //         for (int k = 0; k < m; ++k)
    //         {
    //             if (sorted[k] != -1)
    //             {
    //                 sorted[k] = -1;
    //                 break;
    //             }
    //         }
    //     }
    // }
    int index1 = 0;
    int index2 = 0;
    while (index1 != m)
    {
        if (max_array[index2] > sorted[index1])
        {
            index1++;
        }
        else
        {
            index1++;
            index2++;
            count++;
        }
    }

    return count;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int f = 0; f < t; f++)
    {
        int k, m;
        scanf("%d %d", &k, &m);
        int **student = (int **)malloc(k * sizeof(int *));
        for (int i = 0; i < k; ++i)
        {
            student[i] = (int *)malloc(sizeof(int) * m);
        }
        int col = 0;
        int row = 0;
        for (int i = 0; i < k * m; ++i)
        {
            int a;
            scanf("%d", &a);
            student[row][col] = a;
            row++;
            if (row == k)
            {
                col++;
                row = 0;
            }
        }
        int schoolno;
        scanf("%d", &schoolno);
        int *max_arr = max_array(student, k, m, schoolno);
        mergesortd(max_arr, 0, m - 1);
        int *sorted = sortedschool(student, m, schoolno);
        int count = countcalc(sorted, max_arr, k, m);
        printf("%d\n", count);
        free(sorted);
        free(max_arr);
        for(int i=0;i<k;++i){
            free(student[i]);
        }
        free(student);
    }
}