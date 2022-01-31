//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
	int n, h;
	cin >> n >> h;
	int arr[n][3];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	int maximum = INT_MIN;
	for (int b = 0; b < (1 << n); b++)
	{
		int cnt = 0;
		int height = 0;
		set<pair<int, int>> s;
		for (int i = 0; i < n; i++)
		{
			if (b & (1 << i))
			{
				s.insert({-arr[i][2], i});
			}
		}
		cnt += -(*s.begin()).first;
		height += arr[(*s.begin()).second][0];
		set<pair<int, int>>::iterator it = s.begin();
		s.erase(it);
		for (auto u : s)
		{
			cnt += -u.first - arr[u.second][1];
			height += arr[u.second][0];
		}
		if (height >= h)
		{
			maximum = max(cnt, maximum);
		}
	}
	cout << maximum;
}