#include <stdio.h>
#include <stdlib.h>

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


int main()
{
    // int t = 1;
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        // int n = 3;
        int n;
        scanf("%d", &n);
        int maxlength = 600000 / n;
        maxlength = maxlength + 10;
        char **strarray = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; ++i)
        {
            strarray[i] = (char *)malloc(sizeof(char) * maxlength);
        }
        // strcpy(strarray[0], "abc");
        // strcpy(strarray[1], "azcd");
        // strcpy(strarray[2], "abcf");
        // strcpy(strarray[3],"bcdefg");
        // strcpy(strarray[4],"abcdefg");
        // strcpy(strarray[5],"yyyyyyyy");
        // strcpy(strarray[6],"aaaa");
        // strcpy(strarray[7],"abcd");
        // strcpy(strarray[8],"bcde");
        // strcpy(strarray[9],"cdef");

        // int arr[3] = {3, 4, 4};
        int *arr = malloc(sizeof(int) * n);
        // arr[0]=3;
        // arr[1]=4;
        // arr[2]=4;
        // int arr[10]={5,5,5,6,7,8,4,4,4,4};
        // int max = 4;
        // int arr[n];
        // int max = -1;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %s", &arr[i], strarray[i]);
            // if (max < arr[i])
            // {
            //     max = arr[i];
            // }
        }
        mergesortd(strarray,0,n-1,arr,n,maxlength);
        // mergesortd(strarray, 0, n - 1, arr, n, maxlength);
        // for (int k = 1; k < max; ++k)
        // {
        //     for (int i = 0; i < n; ++i)
        //     {
        //         // printf("%d\n",i);
        //         // mergesortd(strarray,0,n-1,arr,i,n,maxlength);
        //         // break;
        //         // printf("\n");
        //         int j = 0;
        //         int starting = 0;
        //         while (1)
        //         {
        //             while (j < n - 1)
        //             {
        //                 // if (strarray[j][k-1] == strarray[j + 1][k-1])
        //                 // {
        //                 //     j++;
        //                 // }
        //                 int l;
        //                 for (l = 0; l < k; ++l)
        //                 {
        //                     if (strarray[j][l] == strarray[j + 1][l])
        //                     {
        //                         continue;
        //                     }
        //                     else
        //                     {
        //                         break;
        //                     }
        //                 }
        //                 if (l == k)
        //                 {
        //                     j++;
        //                 }
        //                 else
        //                 {
        //                     break;
        //                 }
        //             }
        //             // if(j==(n-2) && strarray[n-2][k-1]==strarray[n-1][k-1]){
        //             //     j++;
        //             // }
        //             mergesortd(strarray, starting, j, arr, n, maxlength);
        //             starting = j;
        //             starting++;
        //             j++;
        //             if (j == (n))
        //             {
        //                 break;
        //             }
        //         }
        //     }
        // }
        // prefixes(strarray, arr, n, max);
        for (int i = 0; i < n; ++i)
        {
            printf("%s\n", strarray[i]);
        }
        free(arr);
        for(int i=0;i<n;++i){
            free(strarray[i]);
        }
        free(strarray);
    }
}