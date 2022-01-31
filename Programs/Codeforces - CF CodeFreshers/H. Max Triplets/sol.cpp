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

lll check(vector<lll> &arr, lll n, lll guess)
{
    bool flag1 = false;
    lll sec = guess;
    for (lll fir = 0; fir < guess; fir++)
    {
        lll thir = n - guess + fir;
        bool flag2 = false;
        if (2 * arr[fir] > arr[n - guess - 1])
        {
            break;
        }
        sec = lower_bound(arr.begin() + sec, arr.begin() + n - guess, 2 * arr[fir]) - arr.begin();
        if (2 * arr[sec] <= arr[thir])
        {
            flag2 = true;
            sec++;
        }
        if (!flag2)
        {
            break;
        }
        if (fir == guess - 1)
        {
            flag1 = true;
        }
    }
    return flag1;
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
        lll n;
        cin >> n;
        vector<lll> arr(n);
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (n < 3)
        {
            cout << 0 << "\n";
            continue;
        }
        lll low = 1, high = (n / 3), res = -1;
        while (low <= high)
        {
            lll mid = (low + high) / 2;

            if (check(arr, n, mid))
            {
                res = max(res, mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (res == -1)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << res << "\n";
        }
    }
}