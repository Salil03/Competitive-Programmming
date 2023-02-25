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

bitset<10000003> Primes;
void SieveOfEratosthenes(lll n)
{
    Primes[0] = 1;
    for (lll i = 3; i * i <= n; i += 2)
    {
        if (Primes[i / 2] == 0)
        {
            for (lll j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    SieveOfEratosthenes(10000003);
    vector<lll> prime_nums;
    for (lll i = 1; i <= 10000002; i++)
    {
        if (i == 2)
        {
            prime_nums.emplace_back(i);
        }
        else if (i % 2 == 1 && Primes[i / 2] == 0)
        {
            prime_nums.emplace_back(i);
        }
    }
    lll n;
    cin >> n;
    while (n--)
    {
        lll x, y;
        cin >> x >> y;
        bool flag = false;
        lll minimum = INT_MAX;
        if (gcd(x, y) > 1)
        {
            cout << 0 << "\n";
            continue;
        }
        lll num = max(x, y) - min(x, y);
        for (lll i : prime_nums)
        {
            if (i * i > num)
            {
                break;
            }
            if (num % i != 0)
            {
                continue;
            }
            else
            {
                flag = true;
                minimum = min(minimum, i - (x % i));
                lll other = num / i;
                minimum = min(minimum, other - (x % other));
            }
        }
        if ((x % num == y % num) && max(x, y) - min(x, y) != 1)
        {
            flag = true;
            minimum = min(minimum, num - (max(x, y) % num));
        }
        if (!flag)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << minimum << "\n";
        }
    }
}