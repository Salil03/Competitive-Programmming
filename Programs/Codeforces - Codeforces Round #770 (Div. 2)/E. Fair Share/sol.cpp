#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

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
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

map<lll, char> mp;
map<lll, lll> val;
map<lll, lll> cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll m;
    cin >> m;
    vector<char> ans[m];
    bool flag = true;
    for (lll k = 0; k < m; k++)
    {
        val.clear();
        cnt.clear();
        lll left = 0, right = 0;
        lll n;
        cin >> n;
        ans[k].resize(n, 'P');
        if (n % 2 == 1)
        {
            cout << "NO";
            return 0;
        }
        lll arr[n];

        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
            cnt[arr[i]]++;
        }

        for (lll i = 0; i < n; i++)
        {
            if (val.find(arr[i]) != val.end())
            {
                if (val[arr[i]] == 'L')
                {
                    ans[k][i] = 'R';
                    val[arr[i]] = 'R';
                    right++;
                }
                else
                {
                    ans[k][i] = 'L';
                    val[arr[i]] = 'L';
                    left++;
                }
            }
            else if (mp.find(arr[i]) != mp.end() && cnt[arr[i]] & 1)
            {
                if (mp[arr[i]] == 'L')
                {
                    ans[k][i] = 'R';
                    val[arr[i]] = 'R';
                    right++;
                }
                else
                {
                    ans[k][i] = 'L';
                    val[arr[i]] = 'L';
                    left++;
                }
                mp.erase(arr[i]);
            }
        }
        for (lll i = 0; i < n; i++)
        {
            if (val.find(arr[i]) != val.end() && ans[k][i] == 'P')
            {
                if (val[arr[i]] == 'L')
                {
                    ans[k][i] = 'R';
                    val[arr[i]] = 'R';
                    right++;
                }
                else
                {
                    ans[k][i] = 'L';
                    val[arr[i]] = 'L';
                    left++;
                }
            }
            else if (cnt[arr[i]] & 1 && ans[k][i] == 'P')
            {
                if (left > right)
                {
                    ans[k][i] = 'R';
                    val[arr[i]] = 'R';
                    right++;
                    mp[arr[i]] = 'R';
                }
                else
                {
                    ans[k][i] = 'L';
                    val[arr[i]] = 'L';
                    left++;
                    mp[arr[i]] = 'L';
                }
            }
            else if (cnt[arr[i]] % 2 == 0 && ans[k][i] == 'P')
            {
                ans[k][i] = 'L';
                val[arr[i]] = 'L';
                left++;
            }
        }
        if (left != right)
        {
            flag = false;
        }
    }
    if (mp.empty() && flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    for (lll i = 0; i < m; i++)
    {
        for (char j : ans[i])
        {
            cout << j;
        }
        cout << "\n";
    }
}