#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

/*
$alil03
Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		if(r2 >= r1)
		{
			if(abs(c1 - c2) == 0)
			{
				if(abs(r1 - r2) & 1)
				{
					cout << "Black\n";
				}
				else
				{
					cout << "White\n";
				}
			}
			else if(abs(c1 - c2) == 1 && r1 != r2)
			{
				if(abs(r1 - r2) & 1)
				{
					cout << "White\n";
				}
				else
				{
					cout << "Black\n";
				}
			}
			else
			{
				if(8 - r1 > r2 - 1)
				{
					cout << "White\n";
				}
				else
				{
					cout << "Black\n";
				}
			}
		}
		else if(r2 < r1)
		{
				if(8 - r1 > r2 - 1)
				{
					cout << "White\n";
				}
				else
				{
					cout << "Black\n";
				}
		}
	}
}