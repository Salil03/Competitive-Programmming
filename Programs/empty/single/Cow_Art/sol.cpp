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
char arr[110][110];
bool visited[110][110] = {{0}};
void dfs(lll n, lll row, lll col)
{
    if (visited[row][col])
    {
        return;
    }
    visited[row][col] = true;
    if (row > 0 && arr[row - 1][col] == arr[row][col])
    {
        dfs(n, row - 1, col);
    }
    if (row < n - 1 && arr[row + 1][col] == arr[row][col])
    {
        dfs(n, row + 1, col);
    }
    if (col > 0 && arr[row][col - 1] == arr[row][col])
    {
        dfs(n, row, col - 1);
    }
    if (col < n - 1 && arr[row][col + 1] == arr[row][col])
    {
        dfs(n, row, col + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cowart.in", "r", stdin);
    freopen("cowart.out", "w", stdout);
    lll n;
    cin >> n;
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    lll cnt_1 = 0;
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(n, i, j);
                cnt_1++;
            }
        }
    }
    lll cnt_2 = 0;
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < n; j++)
        {
            visited[i][j] = 0;
            if (arr[i][j] == 'R')
            {
                arr[i][j] = 'G';
            }
        }
    }
    for (lll i = 0; i < n; i++)
    {
        for (lll j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(n, i, j);
                cnt_2++;
            }
        }
    }
    cout << cnt_1 << " " << cnt_2;
}