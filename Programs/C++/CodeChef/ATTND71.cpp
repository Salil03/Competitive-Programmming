#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/LTIME71B/problems/ATTND

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
		pair<string, string> arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		for (int i = 0; i < n; i++)
		{
			bool found = false;
			for (int j = 0; j < n; j++)
			{
				if (i != j && arr[i].first == arr[j].first)
				{
					found = true;
				}
			}
			if (found)
			{
				cout << arr[i].first << " " << arr[i].second << "\n";
			}
			else
			{
				cout << arr[i].first << "\n";
			}
		}
	}
}