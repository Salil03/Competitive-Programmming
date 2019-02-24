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
	int n;
	cin >>n;
	long long int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n, greater<int>());
	long long int maximum = -1;
	for(int i = 0; i<n; i++)
	{
		maximum = max(maximum, arr[i]*(i+1));
	}
	cout << maximum;
}