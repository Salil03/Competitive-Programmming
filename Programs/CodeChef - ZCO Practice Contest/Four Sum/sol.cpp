//OPTIMIZATIONS
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
	int n, t;
	cin >> n >> t;
	vector<int> arr;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp < t - 2)
		{
			arr.emplace_back(temp);
		}
	}
	n = arr.size();
	ll cnt = 0;
	ll mp[t] = {0};
	for (int i = 2; i < n - 1; i++)
	{
		for (int j = 0; j <= i - 2; j++)
		{
			if (arr[j] + arr[i - 1] < t - 1)
			{
				mp[arr[j] + arr[i - 1]]++;
			}
		}
		for (int j = i + 1; j < n; j++)
		{
			if (t - arr[i] - arr[j] > 0 && mp[t - arr[i] - arr[j]])
			{
				cnt += mp[t - arr[i] - arr[j]];
			}
		}
	}
	cout << cnt;
	return 0;
}