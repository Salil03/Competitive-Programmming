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
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		long long cnt = 0, n = s.length();
		for (char i : s)
		{
			if (i == '1')
			{
				cnt++;
			}
		}
		if (cnt & 1)
		{
			cout << "WIN\n";
		}
		else
		{
			cout << "LOSE\n";
		}
	}
}