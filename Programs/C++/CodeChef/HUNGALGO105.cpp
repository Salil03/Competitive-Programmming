#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/COOK105B/problems/HUNGALGO

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool arr[n] = {0};
		bool row[n] = {0};
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp;
				cin >> temp;
				if (temp == 0)
				{
					arr[j] = 1;
					row[i] = 1;
				}
			}
		}
		bool flag = true;
		for (bool i : arr)
		{
			if (!i)
			{
				flag = false;
				break;
			}
		}
		for (bool i : row)
		{
			if (!i)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}