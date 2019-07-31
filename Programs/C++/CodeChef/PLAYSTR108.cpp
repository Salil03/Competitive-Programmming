#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/COOK108B/problems/PLAYSTR

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
		int n;
		cin >> n;
		string s,r;
		cin >> s >> r;
		int cnt1=0, cnt3=0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '0')
			{
				cnt1++;
			}
			if(r[i] == '0')
			{
				cnt3++;
			}
		}
		if(cnt1 == cnt3)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		
	}
}