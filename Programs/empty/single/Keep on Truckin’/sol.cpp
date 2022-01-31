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
int n;
int dp(vector<int> graph[], int node)
{
	if (node == n + 13)
	{
		return 1;
	}
	int ans = 0;
	for (auto u : graph[node])
	{
		ans += dp(graph, u);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	cin >> n;
	int arr[14 + n] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
	for (int i = 0; i < n; i++)
	{
		cin >> arr[14 + i];
	}
	sort(arr, arr + 14 + n);
	vector<int> graph[14 + n];
	for (int i = 0; i < 14 + n - 1; i++)
	{
		for (int j = i + 1; j < 14 + n; j++)
		{
			if (arr[j] - arr[i] <= b && arr[j] - arr[i] >= a)
			{
				graph[i].push_back(j);
			}
		}
	}
	cout << dp(graph, 0);
}