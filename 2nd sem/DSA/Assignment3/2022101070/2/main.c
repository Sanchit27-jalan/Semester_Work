#include "hash.h"

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    char *str = malloc(sizeof(char) * (n + 1));
    scanf("%s", str);
    char *reverse_str = reverse(str, n);
    long long int *front = array_maker(str, n);
    long long int *back = array_maker(reverse_str, n);
    long long int *prime = prime_array(n);
    int l, r;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &l, &r);
        int y = checker(l, r, front, back, n, prime);
        if (y == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    free(prime);
    free(front);
    free(back);
    free(reverse_str);
    free(str);
}