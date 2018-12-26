#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	pair<string, int> arr[n];
	string final[n];
	for(int i= 0; i<n; i++)
	{
		cin >> arr[i].first;
		final[i] = arr[i].first;
		arr[i].second = i;
		int temp = arr[i].first.length();
		for(int j = 0; j<temp; j++)
		{
			arr[i].first[j] = alpha[lower_bound(s.begin(), s.end(), arr[i].first[j]) - s.begin()];
		}
	}
	sort(arr, arr+n);
	for(int i = 0; i<n-1; i++)
	{
		cout << final[arr[i].second] << " ";
	}
	cout << final[arr[n-1].second];
}