#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int digSum(int n)
{
    if (n == 0)
        return 0;
    return (n % 9 == 0) ? 9 : (n % 9);
}
void check()
{
    for (int i = 0; i <= 100004; i++)
    {
        arr[i] = digSum(i);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int t = 0;
    scanf("%d", &t);
    check();
    for (int j = 0; j < t; j++)
    {
        int m = 0, n = 0, x = 0, ans = 0;
        scanf("%d %d %d", &m, &n, &x);
        for (int i = m; i <= n; i++)
        {
            ans += arr[i] == x;
        }
        printf("%d \n", ans);
    }
}