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
		long long int n,k,v;
		cin >> n >> k >> v;
		long long int sum = 0;
		for(long long int i = 0; i<n; i++)
		{
			long long int temp;
			cin >> temp;
			sum += temp;
		}
		if(v*(n+k) - sum > 0 && (v*(n+k) - sum) % k == 0)
		{
			cout <<  (v*(n+k) - sum)/k << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
}