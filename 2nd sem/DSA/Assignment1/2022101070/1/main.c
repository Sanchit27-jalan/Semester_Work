#include "functions.h"

int main()
{
    int t;
    scanf("%d", &t);
    char arr1[6];
    for (int i = 0; i < t; ++i)
    {
        scanf("%s", arr1);
        if (arr1[4] == '1')
        {
            int n;
            scanf("%d", &n);
            char arr[n + 1];
            scanf("%s", arr);
            reverseString(arr, n);
        }
        else if (arr1[4] == '2')
        {
            int n;
            scanf("%d", &n);
            char *arr=(char *)malloc((n+1)*sizeof(char));
            scanf("%s", arr);
            char *c = compressString(arr, n);
            free(arr);
            printf("%s \n", c);
            free(c);
        }
        else if (arr1[4] == '3')
        {
            int n;
            scanf("%d", &n);
            int *arr=(int *)malloc((n+1)*sizeof(int));
            for (int i = 0; i < n; ++i)
            {
                scanf("%d", &arr[i]);
            }
            int *a = uniqueElements(arr, n);
            free(arr);
            int h = a[0];
            for (int i = 1; i <= h; ++i)
            {
                printf("%d ", a[i]);
            }
            free(a);
            printf("\n");
        }
        else if (arr1[4] == '4')
        {
            int rows, columns;
            scanf("%d %d", &rows, &columns);
            int **matrix;
            matrix = (int **)calloc(rows, sizeof(int *));
            for (int i = 0; i < rows; ++i)
            {
                matrix[i] = (int *)calloc(columns, sizeof(int));
            }
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < columns; ++j)
                {
                    scanf("%d", &matrix[i][j]);
                }
            }
            int **a;
            a = transpose(matrix, rows, columns);
            for (int i = 0; i < columns; ++i)
            {
                for (int j = 0; j < rows; ++j)
                {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            for (int i = 0; i <columns; ++i)
            {
                free(a[i]);
            }
            free(a);
            for (int i = 0; i <rows; ++i)
            {
                free(matrix[i]);
            }
            free(matrix);
        }
    }
}