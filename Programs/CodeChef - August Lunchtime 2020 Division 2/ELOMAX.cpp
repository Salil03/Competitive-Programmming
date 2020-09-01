
// Problem : Ratings and Rankings
// Contest : CodeChef - August Lunchtime 2020 Division 2
// URL : https://www.codechef.com/LTIME87B/problems/ELOMAX
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
		lll n,m;
		cin >> n >> m;
		lll rating[n][m+1] = {{0}};
		pair<lll,lll> sorter[n] = {make_pair(0,0)};
		for(lll i = 0; i<n; i++)
		{
			cin >> rating[i][0];
		}
		lll ranking[n][m] ={{0}};
		for(lll i = 0; i<n; i++)
		{
			for(lll j = 1; j<=m; j++)
			{
				lll temp;
				cin >> temp;
				rating[i][j] = rating[i][j-1] + temp;
			}
		}
		for(lll i = 0; i<m; i++)
		{
			for(lll j = 0; j<n; j++)
			{
				sorter[j] = make_pair(rating[j][i+1], j);
			}
			sort(sorter, sorter+n);
			reverse(sorter, sorter+n);
			for(lll j = 0; j<n; j++)
			{
				if(sorter[j].first == sorter[j-1].first)
				{
					ranking[sorter[j].second][i] = ranking[sorter[j-1].second][i];
				}
				else
				{
					ranking[sorter[j].second][i] = j+1;
				}
			}
		}
		
		pair<lll,lll> peaks[n] = {make_pair(0,0)};
		for(lll i = 0; i<n; i++)
		{
			lll maximum_rating = -1, maximum_rank = INT_MAX;
			for(lll j = 0; j<m; j++)
			{
				if(rating[i][j+1] > maximum_rating)
				{
					maximum_rating = rating[i][j+1];
					peaks[i].first = j;
				}
				if(ranking[i][j] < maximum_rank)
				{
					maximum_rank = ranking[i][j];
					peaks[i].second = j;
				}
			}
		}
		lll cnt = 0;
		for(lll i = 0; i<n; i++)
		{
			if(peaks[i].first != peaks[i].second)
			{
				cnt++;
			}
			
		}
		cout << cnt << "\n";
	}
}