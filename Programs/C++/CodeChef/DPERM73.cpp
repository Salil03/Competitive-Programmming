#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/LTIME73B/problems/DPERM

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin >> t;
	while(t--)
	{
		long long n,d;
		cin >> n >> d;
		long long arr[n];
		for(long long i = 0;i<n; i++)
		{
			cin >> arr[i];
		}
		long long cnt = 0;
		for(long long i = 0; i<n-1; i++)
		{
			for(long long j = i+1; j<n; j++)
			{
				if(arr[i] > arr[j] && arr[i] - arr[j] == d)
				{
					arr[i] ^= arr[j];
					arr[j] ^= arr[i];
					arr[i] ^= arr[j];
					cnt++;
					break;
				}
			}
		}
		bool flag = true;
		for(long long i = 0; i<n-1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << cnt << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
		
	}
}