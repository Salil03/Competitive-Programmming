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

int bore(int x, int arr[], int cnt[])
{
	if(x == 1)
	{
		return cnt[1];
	}
	else if(x == 0)
	{
		return 0;
	}
	return max(bore(x-1, arr, cnt), bore(x-2, arr, cnt) + cnt[x]*x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n], cnt[100005];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	cout << bore(n,arr,cnt);
}