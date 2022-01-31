// OPTIMIZATIONS
//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// OPTIMIZATIONS
#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define _GLIBCXX_DEBUG
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

int N = 317220; //example

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);

    int sieve[N + 1];
    memset(sieve, 0, sizeof(sieve)); //initialize to zero
    for (int x = 2; x * x <= N; x++)
    {
        if (sieve[x])
            continue;
        for (int u = x * x; u <= N; u += x)
        {
            sieve[u] = x;
        }
    }
    vector<lll> primes;

    for (int i = 2; i <= N; i++)
    { //print all prime numbers
        if (!sieve[i])
        {
            primes.emplace_back(i);
        }
    }

    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        if (n & 1)
        {
            auto a = upper_bound(primes.begin(), primes.end(), (lll)sqrt(n));
            lll b = n - *a - 1;
            while (b % *a == 0)
            {
                a++;
                b = n - *a - 1;
            }
            cout << *a << " " << b << " " << 1 << "\n";
        }
        else
        {
            cout << n / 2 << " " << n / 2 - 1 << " " << 1 << "\n";
        }
    }
}