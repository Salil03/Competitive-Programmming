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
    lll n;
    cin >> n;
    vector<lll> arr[n];
    map<pair<lll, lll>, lll> largest;
    lll maximum = 0;
    lll idx1 = -1, idx2 = -1;
    for (lll i = 0; i < n; i++)
    {
        arr[i].resize(3);
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        sort(arr[i].begin(), arr[i].end());
        if (maximum < arr[i][0])
        {
            idx1 = i;
            idx2 = -1;
            maximum = arr[i][0];
        }
        lll fir = arr[i][0], sec = arr[i][1], thir = arr[i][2];
        if (largest.find(make_pair(fir, sec)) != largest.end())
        {
            if (maximum < min({fir, sec, thir + arr[largest[make_pair(fir, sec)]][2]}))
            {
                idx1 = largest[make_pair(fir, sec)];
                idx2 = i;
                maximum = min({fir, sec, thir + arr[largest[make_pair(fir, sec)]][2]});
            }
            if (arr[largest[make_pair(fir, sec)]][2] < thir)
            {
                largest[make_pair(fir, sec)] = i;
            }
        }
        else
        {
            largest[make_pair(fir, sec)] = i;
        }
        if (largest.find(make_pair(sec, thir)) != largest.end())
        {
            if (maximum < min({sec, thir, fir + arr[largest[make_pair(sec, thir)]][0]}))
            {
                idx1 = largest[make_pair(sec, thir)];
                idx2 = i;
                maximum = min({sec, thir, fir + arr[largest[make_pair(sec, thir)]][0]});
            }
            if (arr[largest[make_pair(sec, thir)]][0] < fir)
            {
                largest[make_pair(sec, thir)] = i;
            }
        }
        else
        {
            largest[make_pair(sec, thir)] = i;
        }
        if (largest.find(make_pair(fir, thir)) != largest.end())
        {
            if (maximum < min({fir, thir, sec + arr[largest[make_pair(fir, thir)]][1]}))
            {
                idx1 = largest[make_pair(fir, thir)];
                idx2 = i;
                maximum = min({fir, thir, sec + arr[largest[make_pair(fir, thir)]][1]});
            }
            if (arr[largest[make_pair(fir, thir)]][1] < sec)
            {
                largest[make_pair(fir, thir)] = i;
            }
        }
        else
        {
            largest[make_pair(fir, thir)] = i;
        }
    }
    if (idx2 == -1)
    {
        cout << "1\n"
             << idx1 + 1;
    }
    else
    {
        cout << "2\n"
             << idx1 + 1 << " " << idx2 + 1;
    }
}