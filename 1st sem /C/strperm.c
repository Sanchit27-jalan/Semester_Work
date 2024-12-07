#include <stdio.h>
void swapping(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
    return;
}
void perm(char arr1[], int start, int end)
{
    if (start == (end - 1))
    {
        printf("%s",arr1);
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
    char arr1[3] = {'a','b','a'};
    perm(arr1, 0, 3);
}