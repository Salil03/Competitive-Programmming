#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define f first
#define s second
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	char a[n][m][4];
	ll dis[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dis[i][j] = INT_MAX;
			for (int k = 0; k < 4; k++)
				cin >> a[i][j][k];
		}
	}
	set<pair<ll, pair<ll, ll>>> s;
	dis[0][0] = 0;
	s.insert({0, {0, 0}});
	while (!s.empty())
	{
		pair<ll, pair<ll, ll>> p = *(s.begin());
		s.erase(s.begin());
		ll x = p.s.f, y = p.s.s, cur = p.f;
		//cout<<x<<" "<<y<<endl;
		if (x > 0)
		{
			ll we = 0;
			while (a[x][y][we] != a[x - 1][y][2])
				we++;
			we = (4 - we) % 4;
			//    cout<<"U"<<we<<" ";
			if (dis[x - 1][y] > cur + we)
			{
				dis[x - 1][y] = cur + we;
				s.insert({dis[x - 1][y], {x - 1, y}});
			}
		}
		if (x + 1 < n)
		{
			ll we = 0;
			while (a[x][y][(we + 2) % 4] != a[x + 1][y][0])
				we++;
			we = (4 - we) % 4;
			//      cout<<"D"<<we<<" ";
			if (dis[x + 1][y] > cur + we)
			{
				dis[x + 1][y] = cur + we;
				s.insert({dis[x + 1][y], {x + 1, y}});
			}
		}
		if (y > 0)
		{
			ll we = 0;
			while (a[x][y][(we + 3) % 4] != a[x][y - 1][1])
				we++;
			we = (4 - we) % 4;
			//    cout<<"L"<<we<<" ";
			if (dis[x][y - 1] > cur + we)
			{
				dis[x][y - 1] = cur + we;
				s.insert({dis[x][y - 1], {x, y - 1}});
			}
		}
		if (y + 1 < m)
		{
			ll we = 0;
			while (a[x][y][(we + 1) % 4] != a[x][y + 1][3])
				we++;
			we = (4 - we) % 4;
			//    cout<<"R"<<we<<" ";
			if (dis[x][y + 1] > cur + we)
			{
				dis[x][y + 1] = cur + we;
				s.insert({dis[x][y + 1], {x, y + 1}})
			}
		}
		//   cout<<endl<<endl;
	}
	cout << dis[n - 1][m - 1];
}
