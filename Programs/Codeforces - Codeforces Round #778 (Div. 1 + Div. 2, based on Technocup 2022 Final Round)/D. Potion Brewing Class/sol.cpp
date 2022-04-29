#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
#define fb fflush(stdout)
#define pii pair<int, int>
const int mod = 998244353;
int binexp(int a, int b)
{
    int result = 1;
    if (b == 0)
    {
        return 1;
    }
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b = b / 2;
    }
    return result % mod;
}
bool sorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return false;
        }
    }
    return true;
}
void sieve(vector<int> &prime)
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < 200001; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * 2; j < 200001; j += i)
            {
                if (prime[j] == 0)
                {
                    prime[j] = i;
                }
            }
            prime[i] = i;
        }
    }
}
int newlcm(vector<pair<int, int>> arr, int n, vector<int> &prime)
{
    map<int, int> max_map;
    for (int i = 1; i < n; i++)
    {
        int num = arr[i].second;
        map<int, int> temp;
        while (num > 1)
        {
            int factor = prime[num];
            temp[factor]++;
            num /= factor;
        }
        for (auto it : temp)
        {
            max_map[it.first] = max(max_map[it.first], it.second);
        }
    }
    int ans = 1;
    for (auto it : max_map)
    {
        ans = (ans * binexp(it.first, it.second)) % mod;
    }

    return ans;
}
struct edg
{
    int node;
    int self;
    int other;
};
void dfs(vector<vector<edg>> &v, vector<bool> &visited, int node1, vector<pair<int, int>> &arr)
{
    visited[node1] = true;
    for (auto x : v[node1])
    {
        if (!visited[x.node])
        {
            arr[x.node].first = x.other * arr[node1].first;
            arr[x.node].second = x.self * arr[node1].second;
            int d = gcd(arr[x.node].first, arr[x.node].second);
            arr[x.node].first /= d;
            arr[x.node].second /= d;
            dfs(v, visited, x.node, arr);
        }
    }
}
void solve(vector<int> &prime)
{
    int n;
    cin >> n;
    vector<vector<edg>> v(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        edg p;
        edg q;
        p.node = b;
        q.node = a;
        int d = gcd(x, y);
        x /= d;
        y /= d;
        p.self = x;
        p.other = y;
        q.self = y;
        q.other = x;
        v[a].pb(p);
        v[b].pb(q);
    }
    vector<pair<int, int>> arr(n + 1, make_pair(0, 0));
    vector<bool> visited(n + 1, false);
    arr[0].first = 1;
    arr[0].second = 1;
    arr[1].first = 1;
    arr[1].second = 1;
    dfs(v, visited, 1, arr);
    int cen = newlcm(arr, n + 1, prime);
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        sum = (sum + (arr[i].first * binexp(arr[i].second, mod - 2))) % mod;
    }
    int ans = (cen * sum) % mod;
    cout << ans << '\n';
}
signed main()
{
    vector<int> prime(200001, 0);
    sieve(prime);
    for (int i = 0; i < 200; i++)
    {
        cerr << prime[i] << "\n";
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve(prime);
    }
}