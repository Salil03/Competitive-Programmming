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

/*
$alil03

URL: url

Solution Begins here
*/
bool graph[3003][3003];
void destroy(int node, int degree[], int n, bool choose[])
{
	for (int i = 1; i <= n; i++)
	{
		if (graph[i][node] && choose[i])
		{
			degree[i]--;
			graph[i][node] = 0;
			graph[node][i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int degree[n + 1] = {0};
	bool choose[n + 1];
	for (int i = 1; i <= n; i++)
	{
		choose[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = 0;
		}
	}
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	bool flag = false;
	while (!flag)
	{
		flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (degree[i] < k && choose[i])
			{
				destroy(i, degree, n, choose);
				flag = false;
				choose[i] = 0;
				continue;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (choose[i])
		{
			ans++;
		}
	}
	if (ans > 0)
	{
		cout << "YES\n"
			 << ans;
	}
	else
	{
		cout << "NO";
	}
}