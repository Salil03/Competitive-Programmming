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
    lll t;
    cin >> t;
    for (lll test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        lll n;
        cin >> n;
        vector<string> arr(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        map<char, vector<string>> start;
        map<char, bool> end;
        map<char, vector<string>> only;
        bool poss = true;
        for (lll i = 0; i < n; i++)
        {
            bool flag = true;
            for (auto c : arr[i])
            {
                if (c != arr[i][0])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                only[arr[i][0]].emplace_back(arr[i]);
            }
            else
            {
                if (arr[i][0] == arr[i].back())
                {
                    poss = false;
                    break;
                }
                else
                {
                    if (!start[arr[i][0]].empty() || end[arr[i].back()])
                    {
                        poss = false;
                        break;
                    }
                    else
                    {
                        start[arr[i][0]].emplace_back(arr[i]);
                        end[arr[i].back()] = true;
                    }
                }
            }
        }
        // dbg(only);
        // dbg(end);
        // dbg(start);
        if (!poss)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        char c = '|';
        for (char i = 'A'; i <= 'Z'; i++)
        {
            if (!end[i] && (!start[i].empty() || !only[i].empty()))
            {
                c = i;
                break;
            }
        }
        if (c == '|')
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        lll curr = 0;
        string ans = "";
        while (curr < n)
        {
            for (auto u : only[c])
            {
                ans += u;
                curr++;
            }
            only[c].clear();
            if (start[c].empty())
            {
                if (curr == n)
                {
                    break;
                }
                c = '|';
                for (char i = 'A'; i <= 'Z'; i++)
                {
                    if (!end[i] && (!start[i].empty() || !only[i].empty()))
                    {
                        c = i;
                        break;
                    }
                }
                if (c == '|')
                {
                    break;
                }
            }
            else
            {
                ans += start[c][0];
                char temp = c;
                curr++;
                c = start[c][0].back();
                start[temp].clear();
            }
        }
        if (curr != n)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            // dbg(ans);
            bool visited[26];
            memset(visited, 0, sizeof(visited));
            visited[ans[0] - 'A'] = true;
            poss = true;
            for (lll i = 1; i < ans.length(); i++)
            {
                if (ans[i] != ans[i - 1] && visited[ans[i] - 'A'])
                {
                    poss = false;
                }
                else
                {
                    visited[ans[i] - 'A'] = true;
                }
            }
            if (poss)
            {
                cout << ans << "\n";
            }
            else
            {
                cout << "IMPOSSIBLE\n";
            }
        }
    }
}