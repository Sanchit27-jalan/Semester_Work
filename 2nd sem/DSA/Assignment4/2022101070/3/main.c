#include "sort.h"

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