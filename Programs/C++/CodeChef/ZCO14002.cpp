#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int cost[n];
	for(int i = 0; i<n; i++)
	{
		cin >> cost[i];
	}
	int work[n+1];
	work[0] = 0;
	work[1] = 0;
	work[2] = 0;
	for(int i = 3; i<= n; i++)
	{
		work[i] = cost[i-1] + min({work[i-1], work[i-2],work[i-3]});
	}
	cout << work[n];
}