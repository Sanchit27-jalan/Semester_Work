#include <stdio.h>
#include <stdlib.h>
#define p 31
#define mod 1000000007

long long int *array_maker(char *str, int len)
{
    long long int *prime = malloc(sizeof(long long int) * len);
    long long int t = 1;
    long long int hash = 0;
    int i=0;
    while(1)
    {
        if(i!=len){
            hash = (hash + (((int)str[i] - (int)'a') * t) % mod) % mod;
            if (t < 0)
            {
                t = ((t + mod) * p) % mod;
            }
            else
            {
                t = (t * p) % mod;
            }

            prime[i] = hash;
            i++;
        }
        else{
            break;
        }  
    }
    return prime;
}
char *reverse(char *str, int len)
{
    char *reverse_str = malloc(sizeof(char) * (len + 1));
    int i=0;
    while(1){
        if(i!=len){
            reverse_str[i] = str[len - 1 - i];
            i++;
        }
        else{
            break;
        }
    }
    reverse_str[i] = '\0';
    return (reverse_str);
}
long long int *prime_array(int len)
{
    long long int *prime = malloc(sizeof(long long int) * len);
    long long int t = 1;
    int i=0;
    while(1)
    {
        if(i!=len){
            prime[i] = t;
            if (t < 0)
            {
                t = ((t + mod) * p) % mod;
            }
            else
            {
                t = (t * p) % mod;
            }
            i++;
        }
        else{
            break;
        }
        
    }
    return prime;
}
int checker(int l, int r, long long int *front, long long int *back, int n, long long int *prime)
{
    if (l != r)
    {
        long long int linear_sum = 0;
        long long int linear_back = 0;
        if (l != 1)
        {
            linear_sum = front[r - 1] - front[l - 2];
        }
        else
        {
            linear_sum = front[r - 1];
        }

        int u = n - r;
        if (u != 0)
        {
            linear_back = back[n - l] - back[n - r - 1];
        }
        else
        {
            linear_back = back[n - l];
        }
        if(linear_sum<0){
            linear_sum = (linear_sum + mod) % mod;
        }
        else{
            linear_sum = (linear_sum) % mod;
        }
        if(linear_back<0){
            linear_back = (linear_back + mod) % mod;
        }
        else{
            linear_back = (linear_back) % mod;
        }
        linear_back = (linear_back * prime[l - 1]) % mod;
        linear_sum = (linear_sum * prime[u]) % mod;
        if (linear_sum == linear_back)
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
        return 1;
    }
}

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