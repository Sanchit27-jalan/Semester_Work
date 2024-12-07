#include <stdio.h>
void swapping(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}
void perm(int arr1[], int start, int end)
{
    if (start == (end - 1))
    {
        for (int i = 0; i < end; ++i)
        {
            printf("%d ", arr1[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < end; ++i)
    {
        swapping(&arr1[start], &arr1[i]);
        perm(arr1, start + 1, end);
        swapping(&arr1[start], &arr1[i]);
    }
}
int main()
{
    int arr1[3] = {3, 1, 2};
    perm(arr1, 0, 3);
}