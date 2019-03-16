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
		long long int n,neg=0,pos=0;
		cin >> n;
		long long int temp;
		for(int i = 0; i<n; i++)
		{
			cin >> temp;
			if(temp > 0)
			{
				pos++;
			}
			else if(temp <0)
			{
				neg++;
			}
		}
		if(neg==0)
		{
			cout << pos << " " << pos << "\n";
		}
		else if(pos==0)
		{
			cout << neg << " " << neg << "\n";
		}
		else
		{
			cout << max(pos,neg) << " " << min(neg, pos) << "\n";
		}
	}
}