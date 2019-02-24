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
	int x,y,z;
	cin >> x >> y >> z;
	int a,b,c;
	cin >> a >> b >> c;
	if(a < x)
	{
		cout << "NO";
		return 0;
	}
	if(a-x + b < y)
	{
		cout << "NO";
		return 0;
	}
	if(a-x + b - y + c < z)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}