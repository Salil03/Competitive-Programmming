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
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
lll n, w, h;

void recur(lll idx, lll rem[], pair<lll, lll> arr2[], pair<lll, lll> arr[])
{
	if (rem[idx] == -1)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[idx] == arr2[j])
			{
				cout << j + 1 << " ";
				break;
			}
		}
		return;
	}
	recur(rem[idx], rem, arr2, arr);
	for (int j = 0; j < n; j++)
	{
		if (arr[idx] == arr2[j])
		{
			cout << j + 1 << " ";
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> w >> h;
	pair<lll, lll> arr[n], arr2[n];
	for (lll i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		arr2[i] = arr[i];
	}
	sort(arr, arr + n);
	lll dp[n] = {0};
	lll rem[n] = {-1};
	if (arr[0].first > w && arr[0].second > h)
	{
		dp[0] = 1;
	}
	else
	{
		dp[0] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		rem[i] = -1;
		if (arr[i].first > w && arr[i].second > h)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (arr[i].first > arr[j].first && arr[i].second > arr[j].second && arr[j].first > w && arr[j].second > h)
				{
					if (dp[j] + 1 > dp[i])
					{
						rem[i] = j;
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
	}
	lll ans = *max_element(dp, dp + n);
	if (ans == 0)
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << ans << "\n";
	}
	recur(max_element(dp, dp + n) - dp, rem, arr2, arr);
}