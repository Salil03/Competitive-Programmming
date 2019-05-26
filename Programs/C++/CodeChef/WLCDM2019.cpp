#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const long long int INF = 0x3f3f3f;
const long long int MOD = 1000000007;

/*
$alil03
Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n;
	cin >> n;
	pair<long long int,long long int> arr[n];
	for(long long int i = 0; i<n; i++)
	{
		cin >> arr[i].first;
		arr[i].second=i;
	}
	sort(arr,arr+n);
	for(auto i: arr)
	{
		cout << i.first << " " << i.second << "\n";
	}
}