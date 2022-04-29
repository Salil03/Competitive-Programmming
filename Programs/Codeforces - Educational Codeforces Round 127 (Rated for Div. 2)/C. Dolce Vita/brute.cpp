#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pb push_back
#define vi vector<int>
const int INF = (int)1e18;
const int mod = 1000000007;
#define sz(x) (int)(x).size()

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

int numbit(int x)
{
    int ans = 0;
    while (x > 0)
    {
        x = x >> 1;
        ans++;
    }
    return ans;
}
int setbit(int x)
{
    int ans = 0;
    while (x > 0)
    {
        if (x & 1)
        {
            ans++;
        }
        x = x >> 1;
    }
    return ans;
}
struct edge
{
    int u, v, w;
};

int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int primepow(int x, int p)
{
    int ans = 0;
    while (x % p == 0)
    {
        ans++;
        x /= p;
    }
    return ans;
}
vector<vector<int>> tree(11);

void update(int pos, int val, int n, int k)
{
    int ind = n + pos - 1;
    tree[k][ind] = val;
    ind /= 2;
    while (ind >= 1)
    {
        tree[k][ind] = (tree[k][2 * ind] + tree[k][2 * ind + 1]);
        ind /= 2;
    }
}
int sumrange(int node, int nodelow, int nodehigh, int querylow, int queryhigh, int k)
{
    if (queryhigh < querylow)
    {
        return 0;
    }
    if (querylow <= nodelow && nodehigh <= queryhigh)
    {
        return tree[k][node];
    }
    if (querylow > nodehigh || queryhigh < nodelow)
    {
        return 0;
    }
    int mid = (nodelow + nodehigh) / 2;
    return (sumrange(2 * node, nodelow, mid, querylow, queryhigh, k) + sumrange(2 * node + 1, mid + 1, nodehigh, querylow, queryhigh, k));
}

int numdig(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += 1;
        n /= 10;
    }
    return ans;
}
void normalize(std::vector<int> &v)
{
    std::vector<int> aux = v;
    std::sort(aux.begin(), aux.end());
    aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
    for (int i = 0; i < v.size(); i++)
        v[i] = std::lower_bound(aux.begin(), aux.end(), v[i]) - aux.begin() + 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vi prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (prefix[i + 1] <= x)
            {
                ans += (x - prefix[i + 1]) / (i + 1) + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}