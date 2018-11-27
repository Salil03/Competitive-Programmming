#include<bits/stdc++.h>
using namespace std;
long long dp[104];
int lis(long long arr[], int n )
{
    long long lis[n];

    lis[0] = 1;

    for (int i = 1; i < n; i++ )
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++ )
        {
            if ( arr[i] >= arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    return *max_element(lis, lis+n);
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
		cin >> n;
		long long arr[n];
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		cout << lis(arr,n) << "\n";
	}
}