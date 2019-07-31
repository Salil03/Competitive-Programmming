#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/LTIME73B/problems/PAJAPONG

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
		long long int x,y,k;
		cin >> x >> y >> k;
		long long int sum = x+y;
		if(sum / k & 1)
		{
			cout << "Paja\n";
		}
		else
		{
			cout << "Chef\n";
		}
		
	}
}