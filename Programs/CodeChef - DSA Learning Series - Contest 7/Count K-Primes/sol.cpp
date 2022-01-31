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
const lll MAX = 100005;

vector<lll> smallest(MAX);
lll table[MAX][5];

void precompute(lll num, lll idx)
{
    for (lll i = idx; i < MAX; i += num)
    {
        smallest[i] = num;
    }
}
set<lll> factors;
void num_factors(lll num)
{
    if (num == 1)
    {
        return;
    }
    factors.insert(smallest[num]);
    num_factors(num / smallest[num]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    for (lll i = 0; i < MAX; i++)
    {
        smallest[i] = i;
    }
    for (lll i = 2; i < MAX; i++)
    {
        if (smallest[i] == i)
        {
            precompute(i, i);
        }
    }
    memset(table, 0, sizeof table);
    for (lll i = 2; i < MAX; i++)
    {
        factors.clear();
        num_factors(i);
        lll num = factors.size();
        for (lll j = 0; j < 5; j++)
        {
            table[i][j] = table[i - 1][j];
        }
        if (num <= 5)
        {
            table[i][num - 1]++;
        }
    }
    lll t;
    cin >> t;
    while (t--)
    {
        lll a, b, k;
        cin >> a >> b >> k;
        cout << table[b][k - 1] - table[a - 1][k - 1] << "\n";
    }
}