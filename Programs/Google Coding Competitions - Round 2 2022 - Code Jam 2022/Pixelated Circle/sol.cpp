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

map<pair<lll, lll>, bool> mp;
map<pair<lll, lll>, bool> mp2;
void draw_circle_perimeter(lll R)
{
    for (lll x = -R; x <= R; x++)
    {
        lll y = 0;
        if (sqrt(R * R - x * x) - trunc(sqrt(R * R - x * x)) <= abs(sqrt(R * R - x * x) - round(sqrt(R * R - x * x))))
        {
            y = trunc(sqrt(R * R - x * x));
        }
        else
        {
            y = round(sqrt(R * R - x * x));
        }
        mp[make_pair(x, y)] = true;
        mp[make_pair(x, -y)] = true;
        mp[make_pair(y, x)] = true;
        mp[make_pair(-y, x)] = true;
    }
}

void draw_circle_filled(lll R)
{
    for (lll x = -R; x <= R; x++)
    {
        for (lll y = -R; y <= R; y++)
        {
            lll temp = 0;
            if (sqrt(y * y + x * x) - trunc(sqrt(y * y + x * x)) <= abs(sqrt(y * y + x * x) - round(sqrt(y * y + x * x))))
            {
                temp = trunc(sqrt(y * y + x * x));
            }
            else
            {
                temp = round(sqrt(y * y + x * x));
            }
            if (temp <= R)
            {
                mp2[make_pair(x, y)] = true;
            }
        }
    }
}

void draw_circle_filled_wrong(lll R)
{
    for (lll r = 0; r <= R; r++)
    {
        draw_circle_perimeter(r);
    }
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
    for (lll test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        lll R;
        cin >> R;
        mp.clear();
        mp2.clear();
        draw_circle_filled(R);
        // for (lll i = -R; i <= R; i++)
        // {
        //     for (lll j = -R; j <= R; j++)
        //     {
        //         cout << mp2[make_pair(i, j)] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        // cout << "\n";
        draw_circle_filled_wrong(R);
        // for (lll i = -R; i <= R; i++)
        // {
        //     for (lll j = -R; j <= R; j++)
        //     {
        //         cout << mp[make_pair(i, j)] << " ";
        //     }
        //     cout << "\n";
        // }
        lll sum = 0;
        for (lll i = -R; i <= R; i++)
        {
            for (lll j = -R; j <= R; j++)
            {
                if (mp[make_pair(i, j)] != mp2[make_pair(i, j)])
                {
                    sum++;
                }
            }
        }
        cout << sum << "\n";
    }
}