#include <bits/stdc++.h>
using namespace std;

int main()
{
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
		if (binary_search(a.begin(), a.end(), x))
		{
			cout << (lower_bound(a.begin(), a.end(), x) - a.begin()) + 1 << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
}