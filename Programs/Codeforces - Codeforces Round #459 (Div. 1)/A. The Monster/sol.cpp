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
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

lll recur(lll l, lll r, string &s, bool left, bool right) // true == ), false == (
{
    if (l >= r)
    {
        return 0;
    }
    if (l == r - 1)
    {
        if (s[l] == '(' && s[r] == ')')
        {
            return 1;
        }
        else if (s[l] == '(' && s[r] == '?')
        {
            return right;
        }
        else if (s[l] == '?' && s[r] == ')')
        {
            return (!left);
        }
        else if (s[l] == '?' && s[r] == '?')
        {
            return left != right;
        }
        else
        {
            return 0;
        }
    }

    if (s[l] == '(')
    {
        if (s[r] == ')')
        {
            return 1 + recur(l + 1, r - 1, s, 0, 0);
        }
        else if (s[r] == '?')
        {
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    string s;
    cin >> s;
}