#include "heap.h"

int main()
{
    int n;
    scanf("%d", &n);
    int minus_ct_before_first_positive = 0;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] >= 0)
        {
            break;
        }
        else
        {
            minus_ct_before_first_positive++;
        }
    }
    int ct = 0;
    long long int sum = 0;
    heap h = create(n + 1);
    for (int i = minus_ct_before_first_positive; i < n; i++)
    {
        if (arr[i] < 0)
        {
            insert(h, arr[i]);
        }
        sum = sum + arr[i];
        ct++;
        if (sum < 0)
        {
            long long int t = deleting_min_element(h);
            sum = sum - t;
            ct--;
        }
    }
    printf("%d\n", ct);
}
