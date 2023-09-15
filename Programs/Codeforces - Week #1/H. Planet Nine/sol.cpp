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

vector<pair<bool, lll>> path;
lll recur(lll a, lll b)
{
    if (a == b)
    {
        return 0;
    }
    if (b >= a && (b - a) % 9 == 0)
    {
        path.push_back(make_pair(1, (b - a) / 9));
        return (b - a) / 9;
    }
    else
    {
        string a_str = to_string(a);
        if (a_str[0] == '1')
        {
            lll nearest = 1;
            while (nearest * 10 <= a)
            {
                nearest *= 10;
            }
            path.push_back(make_pair(0, 1));
            return 1 + recur(a - nearest, b);
        }
        lll nearest = 10;
        while (nearest < a)
        {
            nearest *= 10;
        }
        path.push_back(make_pair(1, ((nearest - a) + (9 - (nearest - a) % 9) % 9) / 9));
        path.push_back(make_pair(0, 1));
        return 1 + ((nearest - a) + (9 - (nearest - a) % 9) % 9) / 9 + recur((9 - ((nearest - a) % 9)) % 9, b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll a, b;
    cin >> a >> b;
    recur(a, b);
    if (path.empty())
    {
        cout << "Stable\n0";
        return 0;
    }
    vector<pair<bool, lll>> comp_path;
    comp_path.push_back(path[0]);
    string a_curr = to_string(a);
    if (path[0].first)
    {
        a_curr = to_string(stoi(a_curr) + 9 * path[0].second);
    }
    else
    {
        if (a_curr.length() == path[0].second)
        {
            a_curr = to_string(0);
        }
        else
        {
            a_curr = a_curr.substr(path[0].second, string::npos);
        }
    }
    lll n = path.size();
    lll cnt = 0;
    // dbg(path);
    for (lll i = 1; i < n; i++)
    {
        // dbg(a_curr);
        if (path[i].first == comp_path[cnt].first && path[i].first)
        {
            comp_path[cnt].second += path[i].second;
            a_curr = to_string(stoi(a_curr) + 9 * path[i].second);
        }
        else if (path[i].first == comp_path[cnt].first && !path[i].first)
        {
            if (a_curr[0] == '1')
            {
                if (a_curr.length() == path[i].second)
                {
                    a_curr = to_string(0);
                }
                else
                {
                    a_curr = a_curr.substr(path[i].second, string::npos);
                }
                comp_path[cnt].second += path[i].second;
            }
            else
            {
                a_curr = to_string(stoi(a_curr));
                if (a_curr.length() == path[i].second)
                {
                    a_curr = to_string(0);
                }
                else
                {
                    a_curr = a_curr.substr(path[i].second, string::npos);
                }
                comp_path.push_back(path[i]);
                cnt++;
            }
        }
        else if (path[i].first != comp_path[cnt].first)
        {
            comp_path.push_back(path[i]);
            cnt++;
            if (path[i].first)
            {
                a_curr = to_string(stoi(a_curr) + 9 * path[i].second);
            }
            else
            {
                if (a_curr.length() == path[i].second)
                {
                    a_curr = to_string(0);
                }
                else
                {
                    a_curr = a_curr.substr(path[i].second, string::npos);
                }
            }
        }
    }
    if (comp_path.size() <= 1000)
    {
        cout << "Stable\n";
        cout << comp_path.size() << "\n";
        for (auto i : comp_path)
        {
            if (i.first)
            {
                cout << "+ " << i.second << "\n";
            }
            else
            {
                cout << "- " << i.second << "\n";
            }
        }
    }
    else
    {
        cout << "Broken";
    }
}