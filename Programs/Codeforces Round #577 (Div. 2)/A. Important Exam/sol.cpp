#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

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
	int n, m;
	cin >> n >> m;
	string arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	long long int sum = 0;
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		int mark = 0;
		cin >> mark;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == 'A')
			{
				a++;
			}
			if (arr[j][i] == 'B')
			{
				b++;
			}
			if (arr[j][i] == 'C')
			{
				c++;
			}
			if (arr[j][i] == 'D')
			{
				d++;
			}
			if (arr[j][i] == 'E')
			{
				e++;
			}
		}
		sum += max({a, b, c, d, e}) * mark;
	}
	cout << sum;
}