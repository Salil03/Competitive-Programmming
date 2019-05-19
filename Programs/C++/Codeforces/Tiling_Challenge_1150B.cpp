#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/contest/1150/problem/B

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	char arr[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (arr[i + 1][j] == '.' && arr[i - 1][j] == '.' && arr[i][j + 1] == '.' && arr[i][j - 1] == '.' && arr[i][j] == '.')
			{
				arr[i][j] = '#';
				arr[i + 1][j] = '#';
				arr[i - 1][j] = '#';
				arr[i][j + 1] = '#';
				arr[i][j - 1] = '#';
			}
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (arr[i][j] == '.')
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}