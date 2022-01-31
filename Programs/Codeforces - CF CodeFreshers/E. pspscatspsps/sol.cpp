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

//from gfg
bitset<500001> Primes;
void SieveOfEratosthenes(lll n)
{
    Primes[0] = 1;
    for (lll i = 3; i <= n; i += 2)
    {
        if (Primes[i / 2] == 0)
        {
            for (lll j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}

lll prime(lll h, lll n)
{
    if (h & 1)
        h -= 2;
    else
        h--;

    lll i, j;
    for (i = h; i > n; i -= 2)
    {
        if (i % 2 == 0)
            continue;
        for (j = 3; j <= (lll)sqrt(i); j += 2)
        {
            if (i % j == 0)
                break;
        }
        if (j > (lll)sqrt(i))
            return i;
    }
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n, h;
    cin >> n >> h;
    if (n > (lll)sqrt(h))
    {
        lll ans = prime(h + 1, n);
        if (ans <= n)
        {
            cout << -1;
        }
        else
        {
            cout << ans;
        }
        return 0;
    }
    SieveOfEratosthenes(100000);
    lll primes[9592], curr = 0;
    for (int i = 1; i <= 100000; i++)
    {
        if (i == 2)
        {
            primes[curr] = i;
            curr++;
        }
        else if (i % 2 == 1 && Primes[i / 2] == 0)
        {
            primes[curr] = i;
            curr++;
        }
    }
    lll largest = lower_bound(primes, primes + 9592, sqrt(h) + 3) - primes;
    bool flag = false;
    for (lll i = h; i >= 2; i--)
    {
        bool flag2 = true;
        for (lll j = 0; j <= largest + 1 && primes[j] <= n; j++)
        {
            if (i % primes[j] == 0)
            {
                flag2 = false;
                break;
            }
        }
        if (flag2)
        {
            cout << i;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << -1;
    }
}