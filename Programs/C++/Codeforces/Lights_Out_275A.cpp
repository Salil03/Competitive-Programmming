#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[3][3];
	bool lights[5][5];
	for(int i = 0;i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			cin >> arr[i][j];
			lights[i][j] = 1;
		}
	}
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(arr[i][j] & 1)
			{
				lights[i][j] = !lights[i][j];
				lights[i-1][j] = !lights[i-1][j];
				lights[i][j+1] = !lights[i][j+1];
				lights[i+1][j] = !lights[i+1][j];
				lights[i][j-1] = !lights[i][j-1];
			}
		}
	}
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			cout << lights[i][j];
		}
		cout << "\n";
	}
}