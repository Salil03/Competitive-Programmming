#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pb push_back
#define vi vector<int>
const int INF = (int)1e18;
const int mod = 1000000007;
#define sz(x) ((x).size())

int exp(int k, int m)
{
    if (m == 0)
    {
        return 1;
    }
    int half = exp(k, m / 2);
    if (m % 2 == 1)
    {
        return (((half * half) % mod) * k) % mod;
    }
    else
    {
        return (half * half) % mod;
    }
}
int inv(int x)
{
    return exp(x, mod - 2);
}
int comb(int n, int r)
{
    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans *= (n - i + 1);
        ans %= mod;
        ans *= inv(i);
        ans %= mod;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<double>> dp(n + 1, vector<double>(m + 1));
        vector<vector<int>> dpans(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
            dpans[i][0] = 0;
        }
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
            dpans[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                double c1 = dp[i - 1][j - 1];
                double c2 = dp[i - 1][j];
                if (abs(c1 - c2) > 1e-300 && (c2 - c1) <= 2 * k)
                {
                    dp[i][j] = (c2 - c1) / 2 + dp[i - 1][j - 1];
                    dpans[i][j] = ((((dpans[i - 1][j] + dpans[i - 1][j - 1]) % mod + mod) % mod) * inv(2)) % mod;
                    dpans[i][j] %= mod;
                }
                else
                {
                    dp[i][j] = k + dp[i - 1][j - 1];
                    dpans[i][j] = k + dpans[i - 1][j - 1];
                    dpans[i][j] %= mod;
                }
            }
        }
        cout << dpans[n][m] % mod << "\n";
    }

    return 0;
}