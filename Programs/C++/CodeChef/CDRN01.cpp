#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/COON2019/problems/CDRN01

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
		int b;
		cin >> b;
		int ans = b/10;
		ans *= 10;
		if(ans % 100 == 0)
		{
			ans += 10;
		}
		if(ans < b)
		{
			ans += 10;
		}
		if(ans % 100 == 0)
		{
			ans += 10;
		}
		cout << ans << "\n";
	}
}