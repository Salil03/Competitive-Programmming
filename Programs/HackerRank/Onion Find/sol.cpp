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
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
char arr[760][760];
bool visited[760][760] = {};
lll dfs0(lll row, lll col, lll r, lll c)
{
	if (visited[row][col])
	{
		return 0;
	}
	lll ans = 0;
	if (arr[row][col] == 'O')
	{
		ans++;
	}
	visited[row][col] = true;
	if (row > 0)
	{
		if (arr[row - 1][col] == '.' || arr[row - 1][col] == 'O')
		{
			ans += dfs0(row - 1, col, r, c);
		}
	}
	if (row < r - 1)
	{
		if (arr[row + 1][col] == '.' || arr[row + 1][col] == 'O')
		{
			ans += dfs0(row + 1, col, r, c);
		}
	}
	if (col > 0)
	{
		if (arr[row][col - 1] == '.' || arr[row][col - 1] == 'O')
		{
			ans += dfs0(row, col - 1, r, c);
		}
	}
	if (col < c - 1)
	{
		if (arr[row][col + 1] == '.' || arr[row - 1][col + 1] == 'O')
		{
			ans += dfs0(row, col + 1, r, c);
		}
	}
	return ans;
}
lll dfs1(lll row, lll col, lll r, lll c, bool flag)
{
	if (visited[row][col])
	{
		return 0;
	}
	lll ans = 0;
	if (arr[row][col] == 'O')
	{
		ans++;
	}
	visited[row][col] = true;
	if (flag)
	{
		if (row > 0)
		{
			if (arr[row - 1][col] == '.' || arr[row - 1][col] == 'O')
			{
				ans += dfs1(row - 1, col, r, c, 1);
			}
		}
		if (row < r - 1)
		{
			if (arr[row + 1][col] == '.' || arr[row + 1][col] == 'O')
			{
				ans += dfs1(row + 1, col, r, c, 1);
			}
		}
		if (col > 0)
		{
			if (arr[row][col - 1] == '.' || arr[row][col - 1] == 'O')
			{
				ans += dfs1(row, col - 1, r, c, 1);
			}
		}
		if (col < c - 1)
		{
			if (arr[row][col + 1] == '.' || arr[row - 1][col + 1] == 'O')
			{
				ans += dfs1(row, col + 1, r, c, 1);
			}
		}
	}
	else
	{
		if (row > 0)
		{
			if (arr[row - 1][col] == '.' || arr[row - 1][col] == 'O')
			{
				ans += dfs1(row - 1, col, r, c, 0);
			}
			else if (arr[row - 1][col] == '#')
			{
				ans += dfs1(row - 1, col, r, c, 1);
			}
		}
		if (row < r - 1)
		{
			if (arr[row + 1][col] == '.' || arr[row + 1][col] == 'O')
			{
				ans += dfs1(row + 1, col, r, c, 0);
			}
			else if (arr[row + 1][col] == '#')
			{
				ans += dfs1(row + 1, col, r, c, 1);
			}
		}
		if (col > 0)
		{
			if (arr[row][col - 1] == '.' || arr[row][col - 1] == 'O')
			{
				ans += dfs1(row, col - 1, r, c, 0);
			}
			else if (arr[row][col - 1] == '#')
			{
				ans += dfs1(row, col - 1, r, c, 1);
			}
		}
		if (col < c - 1)
		{
			if (arr[row][col + 1] == '.' || arr[row][col + 1] == 'O')
			{
				ans += dfs1(row, col + 1, r, c, 0);
			}
			else if (arr[row][col + 1] == '#')
			{
				ans += dfs1(row, col + 1, r, c, 1);
			}
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	while (t--)
	{
		lll r, c;
		cin >> r >> c;
		pair<lll, lll> cafe;
		for (lll i = 0; i < 760; i++)
		{
			for (lll j = 0; j < 760; j++)
			{
				arr[i][j] = 'r';
				visited[i][j] = 0;
			}
		}
		for (lll i = 0; i < r; i++)
		{
			for (lll j = 0; j < c; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 'S')
				{
					cafe.first = i;
					cafe.second = j;
				}
			}
		}
		cout << dfs0(cafe.first, cafe.second, r, c) << " ";
		for (lll i = 0; i < 760; i++)
		{
			for (lll j = 0; j < 760; j++)
			{
				visited[i][j] = 0;
			}
		}
		cout << dfs1(cafe.first, cafe.second, r, c, 0) << "\n";
	}
}