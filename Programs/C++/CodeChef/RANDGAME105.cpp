#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/COOK105B/problems/RANDGAME

Solution Begins here
*/

int getFirstSetBitPos(int n)
{
	int position = 1;
	int m = 1;

	while (!(n & m))
	{

		// left shift
		m = m << 1;
		position++;
	}
	return position;
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
		long long n, temp;
		cin >> n;
		temp = n;
		bool win = true;
		while (!(temp & 1))
		{
			temp /= 2;
			win = !win;
		}
		if (win)
		{
			cout << "Win"
				 << endl;
		}
		else
		{
			cout << "Lose"
				 << endl;
			string tempy;
			cin >> tempy;
			continue;
		}
		while (true)
		{
			if (n == 1)
			{
				cout << "-1"
					 << endl;
				n--;
			}
			else if (!(n & 1))
			{
				cout << "/2"
					 << endl;
				n /= 2;
			}
			else
			{
				if (__builtin_popcount(n - 1) == 1 && !(getFirstSetBitPos(n - 1) & 1))
				{
					cout << "-1"
						 << endl;
					n--;
				}
				else if (__builtin_popcount(n + 1) == 1 && !(getFirstSetBitPos(n + 1) & 1))
				{
					cout << "+1"
						 << endl;
					n++;
				}
				else
				{
					cout << "-1"
						 << endl;
					n--;
				}
			}
			string s;
			cin >> s;
			if (s == "/2")
			{
				n /= 2;
			}
			else if (s == "+1")
			{
				n++;
			}
			else if (s == "-1")
			{
				n--;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}