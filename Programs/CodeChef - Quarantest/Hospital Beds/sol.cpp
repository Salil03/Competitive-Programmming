#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define per(i, a, n) for (ll i = n - 1; i >= a; i--)
#define fi first
#define se second
#define maxn 200005
#define VL vector<ll>
#define all(x) (x).begin(), (x).end()
#define flash                         \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

using namespace std;

int main()
{
	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		ll a[n + 1][n + 1] = {0};

		rep(i, 0, n)
		{
			rep(j, 0, n)
					cin >>
				a[i][j];
		}

		ll no = 0;

		rep(i, 0, n)
		{
			rep(j, 0, n)
			{
				if (a[i][j] == 1)
				{
					if (i == 0)
					{
						if (j == 0)
						{
							if ((a[i][j + 1] != 0 && (j + 1) < n) || (a[i + 1][j] != 0 && (i + 1) < n))
								no = 1;
						}
						else if (j == n - 1)
						{
							if ((a[i][j - 1] != 0 && (j - 1) >= 0) || (a[i + 1][j] != 0 && (i + 1) < n))
								no = 1;
						}
						else
						{
							if ((a[i][j + 1] != 0 && (j + 1) < n) || (a[i][j - 1] != 0 && (j - 1) >= 0) || (a[i + 1][j] != 0 && (i + 1) < n))
								no = 1;
						}
					}
					else if (i == n - 1)
					{
						if (j == 0)
						{
							if ((a[i][j + 1] != 0 && (j + 1) < n) || (a[i - 1][j] != 0 && (i - 1) >= 0))
								no = 1;
						}
						else if (j == n - 1)
						{
							if ((a[i][j - 1] != 0 && (j - 1) >= 0) || (a[i - 1][j] != 0 && (i - 1) >= 0))
								no = 1;
						}
						else
						{
							if ((a[i][j + 1] != 0 && (j + 1) < n) || (a[i][j - 1] != 0 && (j - 1) >= 0) || (a[i - 1][j] != 0 && (i - 1) >= 0))
								no = 1;
						}
					}
					else
					{
						if ((a[i][j + 1] != 0 && (j + 1) < n) || (a[i][j - 1] != 0 && (j - 1) >= 0) || (a[i - 1][j] != 0 && (i - 1) >= 0) || (a[i + 1][j] != 0 && (i + 1) < n))
							no = 1;
					}
				}
			}
		}
		if (no == 1)
			cout << "UNSAFE\n";
		else
			cout << "SAFE\n";
	}
}
