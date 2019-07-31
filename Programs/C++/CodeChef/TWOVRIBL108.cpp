#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/COOK108B/problems/TWOVRIBL

Solution Begins here
*/


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	unsigned long long int arr[100000] = {0,1,2};
	for(int i = 3; i<100000; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}
	while(t--)
	{
		unsigned long long int n;
		cin >> n;
		if(binary_search(arr, arr+100000, n))
		{
			cout << lower_bound(arr, arr+100000, n)-arr << "\n";
		}
		else
		{
			cout << upper_bound(arr, arr+100000, n)-arr << "\n";
		}

	}
}