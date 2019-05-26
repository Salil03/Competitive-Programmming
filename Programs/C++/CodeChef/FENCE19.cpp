#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/APRIL19B/problems/FENCE

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
		int n,m,k;
		cin >> n >> m >> k;
		map<pair<int,int>, bool> arr;
		pair<int, int> values[k];
		for(int i = 0; i<k; i++)
		{
			int r,c;
			cin >> r >> c;
			arr[make_pair(r,c)] = 1;
			values[i] = make_pair(r,c);
		}
		long long int len = 0;
		for(int i = 0; i<k; i++)
		{
			if(!arr[make_pair(values[i].first,values[i].second-1)])
			{
				len++;
			}
			if(!arr[make_pair(values[i].first,values[i].second+1)])
			{
				len++;
			}
			if(!arr[make_pair(values[i].first-1,values[i].second)])
			{
				len++;
			}
			if(!arr[make_pair(values[i].first+1,values[i].second)])
			{
				len++;
			}
		}
		cout << len << "\n";
	}
}