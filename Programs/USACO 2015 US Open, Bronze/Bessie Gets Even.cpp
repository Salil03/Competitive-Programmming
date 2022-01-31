
// Problem : Problem 2. Bessie Gets Even
// Contest : USACO - USACO 2015 US Open, Bronze
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=546
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define dbga(x, n) cerr << "\n" << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" << (#x) << " is " << x << endl
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[7][2] = {{0}}; // 0odd 1even
    for (int i = 0; i < n; i++)
    {
        char s;
        int temp;
        cin >> s >> temp;
        if (s == 'B')
        {
            if (temp & 1)
            {
                arr[0][0]++;
            }
            else
            {
                arr[0][1]++;
            }
        }
        else if (s == 'E')
        {
            if (temp & 1)
            {
                arr[1][0]++;
            }
            else
            {
                arr[1][1]++;
            }
        }
        else if (s == 'S')
        {
            if (temp & 1)
            {
                arr[2][0]++;
            }
            else
            {
                arr[2][1]++;
            }
        }
        else if (s == 'I')
        {
            if (temp & 1)
            {
                arr[3][0]++;
            }
            else
            {
                arr[3][1]++;
            }
        }
        else if (s == 'G')
        {
            if (temp & 1)
            {
                arr[4][0]++;
            }
            else
            {
                arr[4][1]++;
            }
        }
        else if (s == 'O')
        {
            if (temp & 1)
            {
                arr[5][0]++;
            }
            else
            {
                arr[5][1]++;
            }
        }
        else if (s == 'M')
        {
            if (temp & 1)
            {
                arr[6][0]++;
            }
            else
            {
                arr[6][1]++;
            }
        }
    }
    lll sum = 0;
    for (int i = 0; i <= 1 << 7; i++)
    {
        lll curr = 0;
        for (int j = 0; j < 7; j++)
        {
            if (i & (1 << j))
            {
                curr += 1;
            }
        }
    }
}