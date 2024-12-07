#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        int n;
        scanf("%d", &n);
        int *a = malloc(sizeof(int) * n);
        int *b = malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &b[i]);
        }
        struct elements *elem = malloc(sizeof(struct elements) * n);
        for (int i = 0; i < n; ++i)
        {
            elem[i].a1 = a[i];
            elem[i].b1 = b[i];
        }
        mergesortd(elem, 0, n - 1);
        // for(int i=0;i<n;++i){
        //     printf("%d %d\n",elem[i].a1,elem[i].b1);
        // }
        for (int i = 0; i < n; ++i)
        {
            a[i] = elem[i].a1;
            b[i] = elem[i].b1;
        }
        // for(int i=0;i<n;++i){
        //     printf("%d %d ")
        // }
        int *c=journaltwocalc(a,b,n);
        printf("%d %d\n", a[n - 1], c[n - 1]);
        free(c);
        free(b);
        free(a);
    }
}