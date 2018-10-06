#include <iostream>
using namespace std;

int main()
{
	int k =0;
	while(cin >> k)
	{
		if(k == 0)
		{
			return 0;
		}
		int n , m;
		cin >> n >> m;
		int x,y;
		for(int i =0; i< k; i++)
		{
			cin >> x >> y;
			if(x == n || y == m)
			{
				cout << "divisa\n";
			}
			else if(x > n && y > m)
			{
				cout << "NE\n";
			}
			else if (x > n && y < m)
			{
				cout << "SE\n";
			}
			else if(x < n && y < m)
			{
				cout << "SO\n";
			}
			else if (x < n && y > m)
			{
				cout << "NO\n";
			}
		}
	}
}