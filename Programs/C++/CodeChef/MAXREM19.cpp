#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/APRIL19B/problems/MAXREM

Solution Begins here
*/


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n;
	cin >> n;
	long long int arr[n];
	for(long long int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	if(n <=1000)
	{
		long long int maximum = -1;
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				 maximum = max(maximum, arr[j] % arr[i]);
			}
		}
		cout << maximum;
		return 0;
	}
	else
	{
		sort(arr, arr+n);
		long long int num = 0;
		for (long long int j = n - 1; j >= 0; j--)
		{
			if (arr[j] < num)
			{
				break;
			}
			if (arr[j] == arr[j + 1])
			{
				continue;
			}

			for (long long int i = arr[j]; i <= arr[n - 1] + arr[j]; i += arr[j])
			{
				num = max(num, arr[lower_bound(arr, arr + n, i) - arr - 1] % arr[j]);
			}
		}
		cout << num;
	}
}