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

lll n, d;

lll cnt(lll idx, bool visited[], bool arr[])
{
    lll maximum = -1;
    lll curr = -1;
    for (lll i = idx; !visited[i]; i = (i + d) % n)
    {
        if (!arr[i])
        {
            curr = 0;
            maximum = max(maximum, curr);
        }
        else
        {
            curr++;
            maximum = max(maximum, curr);
        }
        visited[i] = true;
    }
    return maximum;
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
        cin >> n >> d;
        bool arr[n];
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        lll maximum = -1;
        for (lll i = 0; i < n; i++)
        {
            if (!visited[i] && !arr[i])
            {
                maximum = max(maximum, cnt(i, visited, arr));
            }
        }
        for (lll i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                maximum = -1;
                break;
            }
        }
        cout << maximum << "\n";
    }
}