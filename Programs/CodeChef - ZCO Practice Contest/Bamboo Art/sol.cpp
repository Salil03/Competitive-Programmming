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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	unordered_map<int, int> mp[n];
	mp[1][arr[1] - arr[0]] = 2;
	mp[0][0] = 1;
	mp[1][0] = 1;
	for (int i = 2; i < n; i++)
	{
		mp[i][0] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (mp[j].find(arr[i] - arr[j]) != mp[j].end())
			{
				mp[i][arr[i] - arr[j]] = mp[j][arr[i] - arr[j]] + 1;
			}
			else
			{
				mp[i][arr[i] - arr[j]] = 2;
			}
		}
	}
	int maximum = 1;
	for (int i = 0; i < n; i++)
	{
		for (auto u : mp[i])
		{
			maximum = max(maximum, u.second);
		}
	}
	cout << maximum;
}