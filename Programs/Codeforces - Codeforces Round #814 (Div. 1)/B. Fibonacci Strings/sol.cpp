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
    vector<lll> fibi = {1,
                        1,
                        2,
                        3,
                        5,
                        8,
                        13,
                        21,
                        34,
                        55,
                        89,
                        144,
                        233,
                        377,
                        610,
                        987,
                        1597,
                        2584,
                        4181,
                        6765,
                        10946,
                        17711,
                        28657,
                        46368,
                        75025,
                        121393,
                        196418,
                        317811,
                        514229,
                        832040,
                        1346269,
                        2178309,
                        3524578,
                        5702887,
                        9227465,
                        14930352,
                        24157817,
                        39088169,
                        63245986,
                        102334155,
                        165580141,
                        267914296,
                        433494437,
                        701408733,
                        1134903170,
                        1836311903,
                        2971215073,
                        4807526976,
                        7778742049,
                        12586269025,
                        20365011074,
                        32951280099,
                        53316291173,
                        86267571272,
                        139583862445,
                        225851433717,
                        365435296162,
                        591286729879,
                        956722026041};
    vector<lll> prefix(fibi.size());
    prefix[0] = fibi[0];
    for (lll i = 1; i < fibi.size(); i++)
    {
        prefix[i] = prefix[i - 1] + fibi[i];
    }
    while (t--)
    {
        lll k;
        cin >> k;
        priority_queue<lll> arr;
        lll sum = 0;
        for (lll i = 0; i < k; i++)
        {
            lll x;
            cin >> x;
            sum += x;
            arr.push(x);
        }
        if (!binary_search(prefix.begin(), prefix.end(), sum))
        {
            cout << "NO\n";
            continue;
        }
        lll idx = lower_bound(prefix.begin(), prefix.end(), sum) - prefix.begin();
        bool flag = true;
        lll last = 0;
        while (idx >= 0)
        {
            if (arr.empty())
            {
                flag = false;
                break;
            }
            lll temp = arr.top();
            arr.pop();
            if (fibi[idx] > temp)
            {
                flag = false;
                break;
            }
            else
            {
                temp -= fibi[idx];
                idx--;
                if (last > 0)
                {
                    arr.push(last);
                }
                if (temp > 0)
                {
                    last = temp;
                }
                else
                {
                    last = 0;
                }
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}