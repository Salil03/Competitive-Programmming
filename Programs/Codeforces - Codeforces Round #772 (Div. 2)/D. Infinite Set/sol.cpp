#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define vi vector<int>
const int INF = (int)1e9;
const int mod = 1000000007;
#define sz(x) (x).size()

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
bool checkset(int x, set<int> &dis)
{
    while (x > 0)
    {
        if (dis.count(x) == 1)
        {
            return false;
        }
        if (x & 1)
        {
            x = x >> 1;
            continue;
        }
        if (x % 4 == 0)
        {
            x = x >> 2;
            continue;
        }
        return true;
    }
    return true;
}
int numbit(int x)
{
    int ans = 0;
    while (x > 0)
    {
        x = x >> 1;
        ans += 1;
    }
    return ans;
}
int fib[200001];
int fibprefix[200001];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<int> dis;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];

        if (numbit(x) > p)
        {
            continue;
        }
        if (checkset(x, dis))
        {
            dis.insert(x);
        }
    }

    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= 200000; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }

    fibprefix[0] = 1;
    for (int i = 1; i <= 200000; i++)
    {
        fibprefix[i] = (fibprefix[i - 1] + fib[i]) % mod;
    }
    int ans = 0;
    for (int x : dis)
    {
        ans += fibprefix[p - numbit(x)];
        ans %= mod;
    }
    cout << ans;

    return 0;
}