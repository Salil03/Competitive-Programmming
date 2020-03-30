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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	k++;
	int arr[n][m];
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i > 0)
			{
				if (j > 0 && j < m - 1)
				{
					arr[i][j] = max({arr[i][j], arr[i][j] + arr[i - 1][j - 1], arr[i][j] + arr[i - 1][j + 1]});
				}
				else if (j > 0 && j >= m - 1)
				{
					arr[i][j] = max(arr[i][j], arr[i][j] + arr[i - 1][j - 1]);
				}
				else if (j <= 0 && j < m - 1)
				{
					arr[i][j] = max(arr[i][j], arr[i][j] + arr[i - 1][j + 1]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	int idx = 0, maximum = -1;
	for (int i = 0; i < m; i++)
	{
		if (arr[n - 1][i] > maximum && arr[n - 1][i] % k == 0)
		{
			maximum = arr[n - 1][i];
			idx = i;
		}
	}
	if (maximum == -1)
	{
		cout << -1;
		return 0;
	}
	cout << maximum << "\n"
		 << idx + 1 << "\n";
	for (int i = n - 2; i >= 0; i--)
	{
		if (idx > 0)
		{
			if (idx < m - 1)
			{
				if (arr[i][idx - 1] > arr[i][idx + 1])
				{
					cout << "L";
					idx--;
				}
				else
				{
					cout << "R";
					idx++;
				}
			}
			else
			{
				cout << "L";
				idx--;
			}
		}
		else
		{
			cout << "R";
			idx++;
		}
	}
}