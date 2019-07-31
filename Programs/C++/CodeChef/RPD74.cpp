#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/LTIME74B/problems/RPD

Solution Begins here
*/

int sumofdi(int n,int m)
{
	string s = to_string(n*m);
	int sum = 0;
	for(char i : s)
	{
		sum += i-'0';
	}
	return sum;
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
		int arr[n];
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		int maximum = -1;
		for(int i = 0; i<n-1; i++)
		{
			for(int j =i+1 ;j<n; j++)
			{
				maximum = max(maximum, sumofdi(arr[i], arr[j]));
			}
		}
		cout << maximum << "\n";
	}
}