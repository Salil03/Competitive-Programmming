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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	while (t--)
	{
		lll n;
		cin >> n;
		lll arr[n];
		for (lll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		set<lll> elements;
		set<lll> count;
		elements.insert(arr[0]);
		lll cnt = 1;
		bool flag = true;
		for (lll i = 1; i < n; i++)
		{
			if (arr[i] == arr[i - 1])
			{
				cnt++;
			}
			else
			{
				if (count.find(cnt) != count.end())
				{
					flag = false;
					break;
				}
				else
				{
					count.insert(cnt);
					cnt = 1;
				}
				if (elements.find(arr[i]) != elements.end())
				{
					flag = false;
					break;
				}
				else
				{
					elements.insert(arr[i]);
				}
			}
		}
		if (count.find(cnt) != count.end())
		{
			flag = false;
		}
		else
		{
			count.insert(cnt);
		}
		if (flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}