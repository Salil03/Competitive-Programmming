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
	string s;
	cin >> s;
	int n = s.length();
	int pre[n] = {0};
	for(int i = 1; i<n; i++)
	{
		if(s[i] == s[i-1])
		{
			pre[i]++;
		}
		pre[i] += pre[i-1];
	}
	int m;
	cin >> m;
	while(m--)
	{
		int l,r;
		cin >> l >> r;
		cout << pre[r-1] - pre[l-1] << "\n";
	}
}