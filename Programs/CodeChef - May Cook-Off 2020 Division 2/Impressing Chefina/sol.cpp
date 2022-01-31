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
	int t;
	cin >> t;
	while (t--)
	{
		lll n, m;
		cin >> n >> m;
		lll arr[n * m];
		lll freq[100004] = {0};
		for (lll i = 0; i < n * m; i++)
		{
			cin >> arr[i];
			freq[arr[i]]++;
		}
		lll even = 0, odd = 0;
		stack<lll> even_list, odd_list;
		for (lll i = 0; i < n * m; i++)
		{
			if (freq[i] & 1)
			{
				odd++;
				odd_list.emplace(i);
			}
			else
			{
				even++;
				even_list.emplace(i);
			}
		}
		lll final[n][m];
		memset(final, 0, sizeof(final));
		pair<lll, lll> idx = {0, 0};
		if (m % 2 == 0)
		{
			if (odd_list.empty())
			{
				while (!even_list.empty())
				{
					lll element = even_list.top();
					even_list.pop();
					while (freq[element]--)
					{
						final[idx.first][idx.second] = element;
						final[idx.first][m - idx.second - 1] = element;
						freq[element]--;
						idx.second++;
						if (idx.second == m / 2)
						{
							idx.second == 0;
							idx.first++;
						}
					}
				}
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						cout << final[i][j] << " ";
					}
					cout << "\n";
				}
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else
		{
			if (n % 2 == 1)
			{
				if (odd_list.empty())
				{
					cout << -1 << "\n";
				}
				else
				{
					while (!even_list.empty())
					{
						lll element = even_list.top();
						even_list.pop();
						while (freq[element]--)
						{
							final[idx.first][idx.second] = element;
							final[idx.first][m - idx.second - 1] = element;
							freq[element]--;
							idx.second++;
							if (idx.second == m / 2)
							{
								idx.second == 0;
								idx.first++;
							}
						}
					}
				}
			}
		}
		cout << "next\n";
	}
}