#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100000
struct comparator
{
    int sum;
    double root_sum;
    int alt_sum;
    int sq_sum;
};

int checker(int len, char *input, struct comparator *front, struct comparator *back, int l, int r, int q)
{
    if (l == r)
    {
        return 1;
    }
    else if (q < max)
    {
        int t = r - l + 1;
        char c[t + 1];
        for (int j = 0; j < t; ++j)
        {
            c[j] = input[l + j - 1];
        }
        c[t] = '\0';
        int flag = 0;
        for (int j = 0; j < t / 2; ++j)
        {

            if (c[j] != c[t - j - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
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
        int linear_sum = 0;
        double r_sum = 0;
        int a_sum = 0;
        int linear_back = 0;
        double r_back = 0;
        int a_back = 0;
        int sq_front = 0;
        int sq_back = 0;
        int t = r - l + 1;
        l = l - 1;
        t = t / 2;
        if (l != 0)
        {
            linear_sum = front[l + t - 1].sum - front[l - 1].sum;
            r_sum = front[l + t - 1].root_sum - front[l - 1].root_sum;
            a_sum = front[l + t - 1].alt_sum - front[l - 1].alt_sum;
            sq_front = front[l + t - 1].sq_sum - front[l - 1].sq_sum;
        }
        else
        {
            linear_sum = front[t - 1].sum;
            r_sum = front[t - 1].root_sum;
            a_sum = front[t - 1].alt_sum;
            sq_front = front[t - 1].sq_sum;
        }

        int u = len - r;
        if (u != 0)
        {
            linear_back = back[u + t - 1].sum - back[u - 1].sum;
            r_back = back[u + t - 1].root_sum - back[u - 1].root_sum;
            a_back = back[u + t - 1].alt_sum - back[u - 1].alt_sum;
            sq_back = back[u + t - 1].sq_sum - back[u - 1].sq_sum;
        }
        else
        {
            linear_back = back[t - 1].sum;
            r_back = back[t - 1].root_sum;
            a_back = back[t - 1].alt_sum;
            sq_back = back[t - 1].sq_sum;
        }
        int flag = 0;
        int y = l + r + 1;
        if (y % 2 != 0)
        {
            a_back = -a_back;
        }
        if (a_sum == a_back)
        {
            if (sq_front == sq_back)
            {
                if (linear_back == linear_sum)
                {
                    if (fabs(r_sum - r_back) < 1e-6)
                    {
                        return 1;
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 0)
        {
            return 0;
        }
    }
    return 0;
}

void initializer(char *str, int n, struct comparator *front, struct comparator *back)
{
    int sum = 0;
    double root_sum = 0;
    int alt = 0;
    int square = 0;
    for (int i = 0; i < n; ++i)
    {
        int d = (int)str[i] - (int)'a' + 1;
        sum = sum + d;
        if (i % 2 == 0)
        {
            alt = alt + d;
        }
        else
        {
            alt = alt - d;
        }
        double f = sqrt(d);
        root_sum = root_sum + f;
        square = square + d * d;
        front[i].sum = sum;
        front[i].root_sum = root_sum;
        front[i].alt_sum = alt;
        front[i].sq_sum = square;
    }
    sum = 0;
    root_sum = 0;
    alt = 0;
    square = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int d = (int)str[i] - (int)'a' + 1;
        sum = sum + d;
        if (i % 2 == 0)
        {
            alt = alt + d;
        }
        else
        {
            alt = alt - d;
        }
        double f = sqrt(d);
        root_sum = root_sum + f;
        square = square + d * d;
        back[n - 1 - i].sum = sum;
        back[n - 1 - i].root_sum = root_sum;
        back[n - 1 - i].alt_sum = alt;
        back[n - 1 - i].sq_sum = square;
    }
    return;
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    char *str = malloc(sizeof(char) * (n + 1));
    scanf("%s", str);
    struct comparator *front;
    struct comparator *back;
    front = malloc(sizeof(struct comparator) * n);
    back = malloc(sizeof(struct comparator) * n);
    initializer(str, n, front, back);
    int l, r;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &l, &r);
        int y = checker(n, str, front, back, l, r, q);
        if (y == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}