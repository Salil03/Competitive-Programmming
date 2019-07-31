#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/JUNE19B/problems/PROXYC

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
		long long int d;
		cin >> d;
		string s;
		cin >> s;
		long long int lim = d*75;
		lim = (lim + 100 - 1) / 100;
		long long int cnt = 0;
		for(long long int i = 0; i<d; i++)
		{
			if(s[i] == 'P')
			{
				cnt++;
			}
		}
		long long int maximum = cnt;
		for(long long int i = 2; i<d-2; i++)
		{
			if(s[i] =='A' && ((s[i+1] == 'P' && s[i+2] == 'P') || (s[i-1] == 'P' || s[i-2] == 'P')))
			{
				maximum ++;
			}
		}
		if(maximum >= lim)
		{
			if(cnt >= lim)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << lim - cnt;
			}
		}
		else
		{
			cout << -1 << "\n";
		}
		
	}
}