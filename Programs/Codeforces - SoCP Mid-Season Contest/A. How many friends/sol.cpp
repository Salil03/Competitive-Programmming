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
unordered_map<bitset<168>, lll> mp;
vector<lll> primes(168);
lll maximum = 0;
void hashprimes(lll n)
{
    bitset<168> bt;
    while (n % 2 == 0)
    {
        bt.flip(0);
        n = n / 2;
    }

    for (lll i = 3; i <= (lll)sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            bt.flip(lower_bound(primes.begin(), primes.end(), i) - primes.begin());
            n = n / i;
        }
    }

    if (n > 2)
    {
        bt.flip(lower_bound(primes.begin(), primes.end(), n) - primes.begin());
    }
    mp[bt]++;
    maximum = max(maximum, mp[bt]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll top = 1000;
    SieveOfEratosthenes(top);

    lll curr = 0;
    for (int i = 1; i <= top; i++)
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
    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        maximum = 0;
        mp.clear();
        for (lll i = 0; i < n; i++)
        {
            lll temp;
            cin >> temp;
            if (temp == 1)
            {
                bitset<168> bt;
                mp[bt]++;
                maximum = max(maximum, mp[bt]);
            }
            else
            {
                hashprimes(temp);
            }
        }
        cout << maximum << "\n";
    }
}