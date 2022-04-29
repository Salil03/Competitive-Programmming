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

lll curr = 0;

bool comparator(const string &a, const string &b)
{
    for (lll i = curr - 4; i <= curr; i++)
    {
        if (a[i] < b[i])
        {
            return true;
        }
        else if (a[i] > b[i])
        {
            return false;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, maximum = -1;
    cin >> n;
    vector<string> arr(n);
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
        lll len = arr[i].length();
        maximum = max(maximum, len);
    }
    if (maximum % 5 != 0)
    {
        maximum = maximum + 5 - (maximum % 5);
    }
    curr = maximum - 1;
    for (lll i = 0; i < n; i++)
    {
        lll len = arr[i].length();
        arr[i] = string(maximum - min(maximum, len), '0') + arr[i];
    }
    // dbg(arr_comp);
    // dbg(curr);
    const regex pattern("^0+(?!$)");
    while (curr - 4 >= 0)
    {
        stable_sort(arr.begin(), arr.end(), comparator);
        for (auto u : arr)
        {
            cout << regex_replace(u, pattern, "") << " ";
        }
        cout << "\n";
        curr -= 5;
    }
}