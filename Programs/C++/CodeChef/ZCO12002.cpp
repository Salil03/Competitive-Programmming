#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
const long long int MOD = 1000000007;

/*
$alil03
Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n,x,y;
	cin >> n >> x >> y;
	pair<long long int,long long int> contest[n];
	for(long long int i = 0; i<n; i++)
	{
		cin >> contest[i].first >> contest[i].second;
	}
	sort(contest, contest + n);
	long long int v[x];
	for(long long int i = 0; i<x; i++)
	{
		cin >> v[i];
	}
	long long int w[y];
	for(long long int i = 0; i<y; i++)
	{
		cin >> w[i];
	}
	sort(v, v+x);
	sort(w, w+y);
	long long int minimum = INF;
	for(long long int i = 0; i<n; i++)
	{
		auto s = upper_bound(v, v+x, contest[i].first);
		s--;
		auto e = upper_bound(w, w+y, contest[i].second-1);
		if(*e > *s)
		{
			minimum = min(minimum, *e - *s +1);
		}
	}
	cout << minimum;
}