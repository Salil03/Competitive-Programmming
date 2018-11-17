#include <bits/stdc++.h>
using namespace std;

int a[65007], n, k;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    long long ans = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        if (j < i)
            j = i;
        else if (j >= n)
            break;
        if (a[j] - a[i] >= k)
        {
            i++;
            ans += n - j;
        }
        else
            j++;
    }
    printf("%lld", ans);
    return 0;
}