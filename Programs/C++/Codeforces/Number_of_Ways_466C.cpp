#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://codeforces.com/problemset/problem/466/C

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n], sum = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	int third = sum/3, temp =0;
	bool cnt[n] = {0};
	for(int i = 0; i<n; i++)
	{
		temp += arr[i];
		if(sum - temp + arr[i] == third)
		{
			cnt[i] = 1;
		}
		else
		{
			cnt[i] = 0;
		}
	}
	for(bool j : cnt)
	{
		watch(j);
	}
	int sums[n] = {0};
	sums[n-1] = cnt[n-1];
	for(int i = n-2; i>=0; i--)
	{
		sums[i] += sums[i + 1] + cnt[i];
	}
    for(int i : sums)
	{
		watch(i);
	}
	int ans = 0;
	for(int i = 0; i<n-2; i++)
	{
		if(cnt[i+2] == 1)
		{
			ans += sums[i+2];
		}
	}
	cout << ans;
}