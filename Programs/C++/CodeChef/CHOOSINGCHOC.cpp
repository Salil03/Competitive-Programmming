#include<bits/stdc++.h>
using namespace std;
int dp(int bowls[], int n)
{
	int table[n+3] = {0, bowls[1]};
	for(int i = 2; i<=n; i++)
	{
		table[i] = max(table[i-1], bowls[i] + table[i-2]);
	}
	return table[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n+1] = {0};
	for(int i = 1; i<=n; i++)
	{
		cin >> arr[i];
	}
	cout << dp(arr, n);
}