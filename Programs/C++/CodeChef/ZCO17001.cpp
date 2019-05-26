#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

/*
$alil03
Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,t;
	cin >> n >> t;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);
	long long int ans = 0;
	for(int i = 0; i<n-3; i++)
	{
		if(arr[i] > t)
		{
			break;
		}
		for(int j = i+1; j<n-2; j++)
		{
			if(arr[i] + arr[j] > t)
			{
				break;
			}
			for(int k = j+1; k<n-1; k++)
			{
				if(arr[i] + arr[j] + arr[k] > t)
				{
					break;
				}
				for(int l = k+1; l<n; l++)
				{
					if(arr[i] + arr[j] + arr[k] + arr[l] > t)
					{
						break;
					}
					if(arr[i] + arr[j] + arr[k] + arr[l] == t)
					{
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
}