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
	int n;
	cin >> n;
	while(n--)
	{
		bool a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		if(a==1 && b==0 && c==1 && d ==1 && e==1)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
}