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

bool isPrefix(string str, lll len, lll i, lll k)
{
    // k length sub-string cannot start at index i
    if (i + k > len)
        return false;
    for (lll j = 0; j < k; j++)
    {

        // Character mismatch between the prefix
        // and the sub-string starting at index i
        if (str[i] != str[j])
            return false;
        i++;
    }
    return true;
}

// Function that returns true if str is K-periodic
bool isKPeriodic(string str, lll len, lll k)
{
    // Check whether all the sub-strings
    // str[0, k-1], str[k, 2k-1] ... are equal
    // to the k length prefix of the string
    for (lll i = k; i < len; i += k)
        if (!isPrefix(str, len, i, k))
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lll n = s.length();
        bool visited[26];
        memset(visited, 0, sizeof(visited));
        visited[s[0] - 'a'] = true;
        lll start = 0;
        for (lll i = 1; i < n; i++)
        {
            if (visited[s[i] - 'a'])
            {
                start = i;
                break;
            }
            else
            {
                visited[s[i] - 'a'] = true;
            }
        }
        if (start == 0)
        {
            cout << "YES\n";
            continue;
        }
        bool flag = true;
        for (lll i = start; i < n; i++)
        {
            if (s[i] != s[i % start])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}