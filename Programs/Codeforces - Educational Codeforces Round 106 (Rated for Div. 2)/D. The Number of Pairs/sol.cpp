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

bool prime[20000004];
lll prime_facts[20000004];
vector<lll> primes_till;
void SieveOfEratosthenes(lll n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.

    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes_till.emplace_back(p);
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
    SieveOfEratosthenes(20000001);
    lll n = primes_till.size();
    dbg(n);
    while (t--)
    {
        lll c, d, x;
        cin >> c >> d >> x;
        vector<lll> div;
        for (lll i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i * i == x)
                {
                    div.push_back(i);
                }
                else
                {
                    div.push_back(i);
                    div.push_back(x / i);
                }
            }
        }
        lll ans = 0;
        for (auto g : div)
        {
            lll l = -1;
            if ((x + d * g) % c == 0 && ((x + d * g) / c) % g == 0)
            {
                l = (x + d * g) / c;
            }
            else
            {
                continue;
            }
            // dbg(l);
            // dbg(g);
            lll temp = l / g, cnt = 0;
            // dbg(cnt);
            ans += (1 << cnt);
        }
        cout << ans << "\n";
    }
}