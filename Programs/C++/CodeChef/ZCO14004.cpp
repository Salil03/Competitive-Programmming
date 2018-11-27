#include<bits/stdc++.h>
using namespace std;
int dp(int work[], int n)
{
	int supw[n+3] = {0};
	for(int i = 3; i<=n; i++)
	{
		supw[i] = min({supw[i-3] + work[i-3], supw[i-2] + work[i-2], supw[i-1] + work[i-1]});
	}
	return supw[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int work[n], sum = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> work[i];
		sum += work[i];
	}
	cout << sum - dp(work, n);
}