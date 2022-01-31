//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
                      << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: url

Solution Begins here
*/
bool arr[2510][2510] = {{0}};
bool visited[2510][2510] = {{0}};
void dfs(int row, int col, int n, int m)
{
    if (visited[row][col])
    {
        return;
    }
    visited[row][col] = 1;
    if (row == n - 1 && col == m - 1)
    {
        return;
    }
    if (arr[row + 1][col])
    {
        dfs(row + 1, col, n, m);
    }
    if (arr[row][col + 1])
    {
        dfs(row, col + 1, n, m);
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 1;
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        arr[n][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i][m] = 0;
    }
    int blast[k][4] = {{0}};
    for (int i = 0; i < k; i++)
    {
        cin >> blast[i][0] >> blast[i][1] >> blast[i][2] >> blast[i][3];
        blast[i][0]--;
        blast[i][1]--;
    }
    for (int i = 0; i < k; i++)
    {
        arr[blast[i][0]][blast[i][1]] = 0;
        for (int j = 0; j < n; j++)
        {
            int time = blast[i][1] + j;
            int req = time - abs(blast[i][0] - j) - blast[i][2];
            if (req >= 0 && req % blast[i][3] == 0)
            {
                arr[j][blast[i][1]] = 0;
            }
        }
        for (int j = 0; j < m; j++)
        {
            int time = blast[i][0] + j;
            int req = time - abs(blast[i][1] - j) - blast[i][2];
            if (req >= 0 && req % blast[i][3] == 0)
            {
                arr[blast[i][0]][j] = 0;
            }
        }
    }
    dfs(0, 0, n, m);
    if (visited[n - 1][m - 1])
    {
        cout << "YES\n"
             << n + m - 2;
    }
    else
    {
        cout << "NO\n";
    }
}