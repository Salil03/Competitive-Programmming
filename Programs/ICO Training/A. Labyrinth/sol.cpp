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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
bool visited[2010][2010];
int n, m, r, c;
lll x, y;
char arr[2010][2010];
int dfs(int row, int col, lll right, lll left, bool bottom, bool top)
{
	int cnt = 1;
	if (visited[row][col])
	{
		cnt = 0;
	}
	else
	{
		visited[row][col] = true;
	}
	if (row > 0 && arr[row - 1][col] == '.' && !top)
	{
		cnt += dfs(row - 1, col, right, left, 1, 0);
	}
	if (row < n - 1 && arr[row + 1][col] == '.' && !bottom)
	{
		cnt += dfs(row + 1, col, right, left, 0, 1);
	}
	if (col > 0 && arr[row][col - 1] == '.' && left > 0)
	{
		cnt += dfs(row, col - 1, right, left - 1, 0, 0);
	}
	if (col < m - 1 && arr[row][col + 1] == '.' && right > 0)
	{
		cnt += dfs(row, col + 1, right - 1, left, 0, 0);
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r >> c >> x >> y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << dfs(r - 1, c - 1, y, x, 0, 0);
}