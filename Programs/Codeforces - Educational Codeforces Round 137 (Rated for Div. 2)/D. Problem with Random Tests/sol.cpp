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
    lll l = 0;
    while (s[l] == '0' && l < n)
    {
        l++;
    }
    while (s[l] == '1' && l < n)
    {
        l++;
    }
    if (l == n)
    {
        lll idx = 0;
        while (s[idx] == '0' && idx < n)
        {
            idx++;
        }
        if (idx == n)
        {
            cout << 0 << "\n";
        }
        else
        {
            s.erase(0, s.find_first_not_of('0'));
            cout << s << "\n";
        }
        return 0;
    }
    lll length = n - l;
    ordered_set indices;
    for (lll i = 0; i <= l; i++)
    {
        if (s[i] == '1')
        {
            indices.insert(i);
        }
    }
    lll j = l + 1;
    lll curr = *indices.begin();
    while (j < n)
    {
        if (s[j] == '0')
        {
            auto itr = indices.begin();
            while (itr != indices.end())
            {
                if (s[*itr + j - l] != '1')
                {
                    curr = *itr;
                    itr = indices.erase(itr);
                }
                else
                {
                    itr++;
                }
            }
        }
        j++;
    }
    if (!indices.empty())
    {
        curr = *indices.begin();
    }
    string sub_str = s.substr(curr, length);
    for (lll i = sub_str.length() - 1; i >= 0; i--)
    {
        if (sub_str[i] == '1')
        {
            s[n - (sub_str.length() - i)] = '1';
        }
    }
    lll idx = 0;
    while (s[idx] == '0' && idx < n)
    {
        idx++;
    }
    if (idx == n)
    {
        cout << 0 << "\n";
    }
    else
    {
        s.erase(0, s.find_first_not_of('0'));
        cout << s << "\n";
    }
}