#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/COOK105B/problems/PEWDSVTS

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
		long long n, a, b, x, y, z;
		cin >> n >> a >> b >> x >> y >> z;
		priority_queue<long long> q;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			q.push(temp);
		}
		while (b <= z - y)
		{
			a += x;
			b += y;
		}
		if (a >= z)
		{
			cout << 0 << "\n";
			continue;
		}
		long long ans = 0;
		while (a < z && !q.empty())
		{
			long long c = q.top();
			q.pop();
			a += c;
			if (c > 1)
			{
				q.push(c / 2);
			}
			ans++;
		}
		if (a >= z)
		{
			cout << ans << "\n";
		}
		else
		{
			cout << "RIP\n";
		}
	}
}