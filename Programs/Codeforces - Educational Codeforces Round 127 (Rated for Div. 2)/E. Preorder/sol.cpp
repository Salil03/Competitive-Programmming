#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution < lll>(low, high)(rng)
// uniform_real_distribution<double>(low, high)(rng)

typedef tree<lll, null_type, less<lll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<lll, lll>, null_type, less<pair<lll, lll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// gp_hash_table<int, int> table; unordered map

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 998244353;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

lll ans = 1;
map<lll, string> mp;
string recur(lll node, string &s, lll len)
{
    if (mp.find(node) != mp.end())
    {
        return mp[node];
    }
    if (2 * node >= len)
    {
        mp[node] = s[node - 1];
    }
    else
    {
        string s1 = recur(2 * node, s, len);
        string s2 = recur(2 * node + 1, s, len);
        if (s1 <= s2)
        {
            mp[node] = s[node - 1] + recur(2 * node, s, len) + recur(2 * node + 1, s, len);
        }
        else
        {
            mp[node] = s[node - 1] + recur(2 * node + 1, s, len) + recur(2 * node, s, len);
        }
    }
    return mp[node];
}

void cnt(bool left, lll node, lll len)
{
    if (2 * node >= len)
    {
        if (left)
        {
            if (mp[node] != mp[node + 1])
            {
                ans = (ans * 2) % MOD;
            }
        }
        return;
    }
    if (left)
    {
        if (mp[node] != mp[node + 1])
        {
            ans = (ans * 2) % MOD;
        }
    }
    cnt(1, 2 * node, len);
    cnt(0, 2 * node + 1, len);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;
    string s;
    cin >> s;
    lll len = s.length();
    recur(1, s, len);
    cnt(0, 1, len);
    // dbg(mp);
    cout << ans % MOD;
}