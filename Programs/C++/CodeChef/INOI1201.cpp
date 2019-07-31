#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/INOIPRAC/problems/INOI1201

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	pair<int , int> b[n];
	for(int i = 0; i<n; i++)
	{
		cin >> a[i];
		int x,y;
		cin >> x >> y;
		b[i].first = x+y;
		b[i].second = i; 
	}
	sort(b, b+n);
	int cnt = 0, sum =0;
	for(int i =n-1; i>=0; i--)
	{
		cnt += a[b[i].second];
		sum = max(sum, cnt + b[i].first);
	}
	cout << sum;
}