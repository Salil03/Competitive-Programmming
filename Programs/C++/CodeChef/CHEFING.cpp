#include <bits/stdc++.h>
using namespace std;

int special(string arr[], int n)
{
	bool primes[26];
	for(int i = 0; i<26; i++)
	{
		primes[i] = true;
	}
	for (int i = 0; i < n; i++)
	{
		bool sec[26] = {false};
		for (int j = 0; arr[i][j]; j++)
		{
			if (primes[arr[i][j] - 'a'])
			{
				sec[arr[i][j] - 'a'] = true;
			}
		}
		for(int i = 0; i<26; i++)
		{
			primes[i] = sec[i];
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		if (primes[i])
		{
			ans++;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >>n;
		string arr[n];
		for(int i =0; i<n; i++)
		{
			cin >> arr[i];
		}
		cout << special(arr, n) << "\n";
	}
}
