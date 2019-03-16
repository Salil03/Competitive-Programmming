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
		string s;
		char d;
		cin >> s >> d;
		long long int n=s.length();
		sort(s.begin(), s.end());
		for(int i = 0; i<n; i++)
		{
			if(s[i] > d)
			{
				cout << d;
			}
			else
			{
				cout << s[i];
			}
		}
		cout << "\n";
	}
}