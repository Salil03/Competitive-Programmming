#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		string arr[n];
		int final[n] = {0};
		for(int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		while(k--)
		{
			int temp;
			cin >> temp;
			while(temp--)
			{
				string s;
				cin >> s;
				auto it = find(arr, arr+n, s);
				if(it != arr+n)
				{
					final[it - arr]++;
				}
			}
		}
		for(int i:final)
		{
			if(i)
			{
				cout << "YES ";
			}
			else
			{
				cout << "NO ";
			}
		}
		cout << "\n";
	}
}