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
	int maximum = *max_element(a.begin(), a.end());
	int freq[maximum + 1];
	memset(freq, -1, sizeof freq);
	for (int i = 0; i < n; i++)
	{
		freq[a[i]] = i;
	}
	while (q--)
	{
		int x;
		cin >> x;
		if (x > maximum || freq[x] == -1)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << freq[x] + 1 << "\n";
		}
	}
}