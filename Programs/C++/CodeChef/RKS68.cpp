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
		bool row[n+1] = {0};
		bool column[n+1] = {0};
		int x,y;
		for(int i = 0; i<k; i++)
		{
			cin >> x >> y;
			row[x] = 1;
			column[y] = 1;
		}
		int temp = 0, last = 1;
		pair<int, int> final[n];
		for(int i = 1; i<=n; i++)
		{
			if(row[i] == 0)
			{
				for(int j = last; j<=n; j++)
				{
					if(column[j] == 0)
					{
						final[temp] = {i,j};
						temp++;
						row[i] = 1;
						column[j] = 1;
						last = j;
						break;
					}
				}
			}
		}
		cout << n-k;
		for(int i = 0; i<temp; i++)
		{
			cout << " "<< final[i].first << " " << final[i].second;
		}
		cout << "\n";
	}
}