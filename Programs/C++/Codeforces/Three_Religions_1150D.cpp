#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/contest/1150/problem/D

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	string a = "", b = "", c = "";
	while (q--)
	{
		string temp;
		cin >> temp;
		if (temp == "+")
		{
			cin >> temp;
			if (temp == "1")
			{
				cin >> temp;
				a += temp;
			}
			else if (temp == "2")
			{
				cin >> temp;
				b += temp;
			}
			else if (temp == "3")
			{
				cin >> temp;
				c += temp;
			}
		}
		}
}