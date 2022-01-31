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
//uniform_int_distribution < lll>(low, high)(rng)
//uniform_real_distribution<double>(low, high)(rng)
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
vector<lll> ans(200004, 0);
lll binarySearchCount(vector<lll> &arr, lll n, lll key)
{
    //helper function from gfg
    lll left = 0;
    lll right = n - 1;

    lll count = 0;

    while (left <= right)
    {
        lll mid = (right + left) / 2;
        if (arr[mid] <= key)
        {
            count = mid + 1;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return count;
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
        lll n, m;
        cin >> n >> m;
        vector<lll> left(m), right(m);
        for (lll i = 0; i < m; i++)
        {
            cin >> left[i] >> right[i];
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        lll curr = 0;
        for (lll i = 1; i <= n; i++)
        {
            lll before = binarySearchCount(left, m, i);
            lll after = binarySearchCount(right, m, i - 1);
            if (before == after || before > after + 1)
            {
                ans[curr] = i;
                curr++;
            }
        }
        cout << curr << "\n";
        for (lll i = 0; i < curr; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}