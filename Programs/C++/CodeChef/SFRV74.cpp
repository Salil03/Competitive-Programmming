	#include<bits/stdc++.h>
	using namespace std;

	#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
	const double PI  = 3.141592653589793238463;
	const int MOD = 1000000007;
	const long long MAXI = ULONG_MAX;

	/*
	$alil03

	URL: https://www.codechef.com/LTIME74B/problems/SFRV

	Solution Begins here
	*/

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		long long int n, I;
		cin >> n >> I;
		long long int k = (I*8)/n;
		long long int arr[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr+n);
		long long int cnt = 1;
		for(int i = 1; i<n; i++)
		{
			if(arr[i] != arr[i-1])
			{
				cnt++;
			}
		}
		if(k>19)
		{
			cout << "0";
			return 0;
		}
		long long int K = (long long int)pow(2, k);
		if(K>cnt)
		{
			cout << "0";
			return 0;
		}
		long long int difference = cnt - K;
		long long int minima = 0;
		long long int temp = 
	}