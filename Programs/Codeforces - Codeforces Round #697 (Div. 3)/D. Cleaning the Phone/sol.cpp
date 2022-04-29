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
        lll n, m, sum = 0;
        cin >> n >> m;
        vector<lll> one, two, temp(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> temp[i];
            sum += temp[i];
        }
        for (lll i = 0; i < n; i++)
        {
            lll b;
            cin >> b;
            if (b == 1)
            {
                one.emplace_back(temp[i]);
            }
            else
            {
                two.emplace_back(temp[i]);
            }
        }
        if (sum < m)
        {
            cout << -1 << "\n";
            continue;
        }
        sort(one.begin(), one.end(), greater<lll>());
        sort(two.begin(), two.end(), greater<lll>());
        one.insert(one.begin(), 0);
        two.insert(two.begin(), 0);
        sum = 0;
        lll l = 1, r = 1, cnt = 0, len1 = one.size(), len2 = two.size();
        while (sum < m)
        {
            if (one[(l < len1) * l] + one[(l + 1 < len1) * (l + 1)] >= min(m - sum, two[(r < len2) * r]))
            {
                sum += one[l];
                l += 1;
                cnt++;
            }
            else
            {
                sum += two[r];
                r++;
                cnt += 2;
            }
        }
        cout << cnt << "\n";
    }
}