#include <stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; ++k)
    {
        int n;
        scanf("%d", &n);
        if (n % 2 == 0)
        {
            printf("%d %d \n", n / 2, n / 2);
        }
        else
        {
            int arr[n / 2];
            for (int i = 1; i < n / 2 + 2; ++i)
            {
                arr[i - 1] = lcm(i, n - i);
            }
            int min = 1000000000;
            for (int j = 0; j < n / 2; ++j)
            {
                if (min > arr[j])
                {
                    min = arr[j];
                }
            }
            printf("%d %d \n", n - min, min);
        }
    }
}