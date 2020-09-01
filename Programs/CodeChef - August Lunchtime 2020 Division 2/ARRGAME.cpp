
// Problem : Game on a Strip
// Contest : CodeChef - August Lunchtime 2020 Division 2
// URL : https://www.codechef.com/LTIME87B/problems/ARRGAME
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
	while(t--)
	{
		lll n;
		cin >> n;
		lll arr[n] = {0};
		for(lll i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		vector<lll> space;
		lll cnt = 0;
		for(lll i = 0; i<n; i++)
		{
			if(arr[i] == 0)
			{
				cnt++;
			}
			else
			{
				if(cnt > 0)
				{
					space.push_back(cnt);
				}
				cnt = 0;
			}
		}
		if(cnt>0)
		{
			space.push_back(cnt);
		}
		lll len = space.size();
		sort(space.begin(), space.end());
		bool win = false;
		reverse(space.begin(), space.end());
		lll odd_largest = 0, odd_largest_2 = 0, even_largest = 0;
		for(lll i = 0; i<len; i++)
		{
			if(space[i] &1)
			{
				if(space[i] > odd_largest)
				{
					odd_largest_2 = odd_largest;
					odd_largest = space[i];
				}
				else if(space[i] > odd_largest_2)
				{
					odd_largest_2  = space[i];
				}
			}
			else
			{
				even_largest = max(even_largest, space[i]);
			}
		}
		if(odd_largest == 0|| count(space.begin(), space.end(), odd_largest) > 1)
		{
			win = false;
		}
		else if(odd_largest/ 2 + 1 <= even_largest || odd_largest/2 + 1 <= odd_largest_2)
		{
			win = false;
		}
		else
		{
			win = true;
		}
		if(win)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}