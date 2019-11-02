#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
    int n;
    cin >> n;
    int a[n + 3];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int dp1[n + 2][n + 2], dp2[n + 2][n + 2];
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            dp1[i][j] = 0;
            dp2[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j > i)
                continue;
            if (i == j)
            {
                dp1[j][i] = 1;
                continue;
            }
            if (a[j] == a[i])
            {
                if (abs(j - i) == 1)
                    dp1[j][i] = 1;
                else
                    dp1[j][i] = dp1[j + 1][i - 1];
            }
            else
            {
                dp1[j][i] = 0;
            }
        }
    }
    dp2[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                continue;
            if (dp1[i][j] == 1)
            {
                int mn = 1e9;
                for (int k = i - 1; k >= 0; k--)
                {
                    mn = min(mn, dp2[k][i - 1]);
                }
                dp2[i][j] = mn + 1;
            }
            else
            {
                dp2[i][j] = dp2[i][j - 1] + 1;
            }
        }
    }
    int mn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        mn = min(mn, dp2[i][n]);
    }
    cout << mn << endl;
    return 0;
}