#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
#define NO_OF_CHARS 256

/*
$alil03

URL: https://www.codechef.com/DARG2019/problems/TUPALIN

Solution Begins here
*/

bool ispalin(string str)
{

	int count[NO_OF_CHARS] = {0};

	for (int i = 0; str[i]; i++)
		count[str[i]]++;

	int odd = 0;
	for (int i = 0; i < NO_OF_CHARS; i++)
	{
		if (count[i] & 1)
			odd++;

		if (odd > 1)
			return false;
	}

	return true;
}

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
		string s;
		string temp;
		cin >> temp;
		s += temp;
		n--;
		while (n--)
		{
			cin >> temp;
			s += " " + temp;
		}
		if (ispalin(s) == 1)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << "\n";
	}
}