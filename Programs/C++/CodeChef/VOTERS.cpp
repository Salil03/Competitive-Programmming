#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: https://www.codechef.com/problems/VOTERS

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	int arr1[n1],arr2[n2], arr3[n3];
	for(int i = 0; i<n1; i++)
	{
		cin >> arr1[i];
	}
	for(int i = 0; i<n2; i++)
	{
		cin >> arr2[i];
	}
	for(int i = 0; i<n3; i++)
	{
		cin >> arr3[i];
	}
	int i = 0,j=0, k=0;
	vector<int> final;
	while(i<n1|| j<n2|| k<n3)
	{
		int one=INT_MAX,two=INT_MAX,three=INT_MAX;
		if(i<n1)
		{
			one=arr1[i]; 
		}
		if(j<n2)
		{
			two=arr2[j]; 
		}
		if(k<n3)
		{
			three=arr3[k]; 
		}
		int minimum = min({one, two,three});
		int cnt = 0;
		if(arr1[i] == minimum)
		{
			i++;
			cnt++;
		}
		if(arr2[j] == minimum)
		{
			j++;
			cnt++;
		}
		if(arr3[k] == minimum)
		{
			k++;
			cnt++;
		}
		if(cnt >= 2)
		{
			final.emplace_back(minimum);
		}
	}
	cout << final.size() << "\n";
	for(int num : final)
	{
		cout << num << "\n";
	}
}