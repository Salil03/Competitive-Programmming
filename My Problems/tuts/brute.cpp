#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (q--)
	{
		int x;
		cin >> x;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == x)
			{
				cout << i + 1 << "\n";
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << -1 << "\n";
		}
	}
}