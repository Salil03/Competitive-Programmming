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
long long int min_2[1010][1010] = {}, min_5[1010][1010] = {};

void recur2(long long int row, long long int col)
{
	if (row > 0 && col > 0)
	{
		if (min_2[row - 1][col] <= min_2[row][col - 1])
		{
			recur2(row - 1, col);
			cout << 'D';
		}
		else
		{
			recur2(row, col - 1);
			cout << 'R';
		}
	}
	else if (row > 0)
	{
		recur2(row - 1, col);
		cout << 'D';
	}
	else if (col > 0)
	{
		recur2(row, col - 1);
		cout << 'R';
	}
	else
	{
		return;
	}
}
void recur5(long long int row, long long int col)
{
	if (row > 0 && col > 0)
	{
		if (min_5[row - 1][col] <= min_5[row][col - 1])
		{
			recur5(row - 1, col);
			cout << 'D';
		}
		else
		{
			recur5(row, col - 1);
			cout << 'R';
		}
	}
	else if (row > 0)
	{
		recur5(row - 1, col);
		cout << 'D';
	}
	else if (col > 0)
	{
		recur5(row, col - 1);
		cout << 'R';
	}
	else
	{
		return;
	}
}

long long int div2(long long int num)
{
	long long int cnt = 0;
	while (num % 2 == 0 && num > 0)
	{
		cnt++;
		num /= 2;
	}
	return cnt;
}
long long int div5(long long int num)
{
	long long int cnt = 0;
	while (num % 5 == 0 && num > 0)
	{
		cnt++;
		num /= 5;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n;
	cin >> n;
	long long int arr[n][n];
	for (long long int i = 0; i < n; i++)
	{
		for (long long int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	min_2[0][0] = div2(arr[0][0]);
	min_5[0][0] = div5(arr[0][0]);
	for (long long int i = 0; i < n; i++)
	{
		for (long long int j = 0; j < n; j++)
		{
			if (i > 0 || j > 0)
			{
				min_2[i][j] = INT_MAX;
				min_5[i][j] = INT_MAX;
			}
			if (i > 0)
			{
				min_2[i][j] = min(min_2[i][j], min_2[i - 1][j] + div2(arr[i][j]));
				min_5[i][j] = min(min_5[i][j], min_5[i - 1][j] + div5(arr[i][j]));
			}
			if (j > 0)
			{
				min_2[i][j] = min(min_2[i][j], min_2[i][j - 1] + div2(arr[i][j]));
				min_5[i][j] = min(min_5[i][j], min_5[i][j - 1] + div5(arr[i][j]));
			}
		}
	}
	if (min_2[n - 1][n - 1] <= min_5[n - 1][n - 1])
	{
		cout << min_2[n - 1][n - 1] << "\n";
		recur2(n - 1, n - 1);
	}
	else
	{
		cout << min_5[n - 1][n - 1] << "\n";
		recur5(n - 1, n - 1);
	}
}