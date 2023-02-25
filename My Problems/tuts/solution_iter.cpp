#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int l, int r, int x)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}

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
		if (binarySearch(a, 0, n - 1, x) != -1)
		{
			cout << binarySearch(a, 0, n - 1, x) + 1 << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
}