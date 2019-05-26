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
	long long int n,k;
	cin >> n >> k;
	long long int arr[k];
	for(long long int i = 0; i<k; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+k);
	bool sieve[n+1] = {0};
	for(long long int i: arr)
	{
		for(int j = i; j<=n; j+=i)
		{
			sieve[j] = 1;
		}
	}
	long long int cnt = 0;
	for(long long int i = 1; i<=n; i++)
	{
		if(!sieve[i])
		{
			cnt++;
		}
	}
	cout << cnt;
}