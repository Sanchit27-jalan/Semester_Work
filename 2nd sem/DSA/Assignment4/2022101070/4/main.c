#include "sort.h"

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