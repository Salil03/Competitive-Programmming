#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		long long arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++)
		{
			int sum = arr[i];
			for (int k = i + 1; k < n; k++)
			{
				sum ^= arr[k];
				if (sum == 0)
				{
					ans += k - i;
				}
			}
		}
		cout << ans << "\n";
	}
}