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
void multiply(lll F[2][2], lll M[2][2]);

void power(lll F[2][2], lll n);

lll fib(lll n, lll a, lll b)
{
    lll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    lll temp[2][2] = {{a + b, b}, {b, a}};
    multiply(F, temp);
    return F[0][0] % MOD;
}

void power(lll F[2][2], lll n)
{
    if (n == 0 || n == 1)
        return;
    lll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

void multiply(lll F[2][2], lll M[2][2])
{
    lll x = (F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD;
    lll y = (F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD;
    lll z = (F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD;
    lll w = (F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD;

    F[0][0] = x % MOD;
    F[0][1] = y % MOD;
    F[1][0] = z % MOD;
    F[1][1] = w % MOD;
}

int main()
{
    lll n, a, b;
    cin >> n >> a >> b;
    n -= 2000;
    cout << fib(n - 1, a, b) % MOD;

    return 0;
}