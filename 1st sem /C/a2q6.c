#include <stdio.h>
void printing(int arr[], int i, int arr1[], int t, int k, int n)
{
    if (t == 1)
    {
        for (int j = (i + 1); j < n; ++j)
        {
            arr1[k - 1] = arr[j];
            for (int u = 0; u < k; ++u)
            {
                printf("%d ", arr1[u]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int j = (i + 1); j <= (n-t); ++j)
        {
            arr1[k - t] = arr[j];
            printing(arr, j, arr1, t - 1, k, n);
        }
    }
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    if (k == 1)
    {
        for (int l = 0; l < n; ++l)
        {
            printf("%d \n", arr[l]);
        }
    }
    else
    {
        int arr1[k];
        for (int m = 0; m < k; ++m)
            {
                arr1[m] = 0;
            }
        for (int j = 0; j <= (n - k); ++j)
        {
            arr1[0] = arr[j];
            printing(arr, j, arr1, k - 1, k, n);
        }
    }
}