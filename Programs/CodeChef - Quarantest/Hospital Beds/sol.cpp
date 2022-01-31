//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

#define watch(x) cerr << "\n" \
					  << (#x) << " is " << (x) << endl
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		int n, flag = 0;
		cin >> n;

		int a[n][n];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		/*
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }*/

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//     cout<<i<<" "<<j<<endl;

				if (a[i][j] == 1)
				{
					if ((i - 1 >= 0 && a[i - 1][j] == 1) || (j - 1 >= 0 && a[i][j - 1] == 1) || (i + 1 < n && a[i + 1][j] == 1) || (j + 1 < n && a[i][j + 1] == 1))
					{
						flag = 1;
						break;
					}
				}
			}
			// cout<<"flag = "<<flag<<endl;
			if (flag == 1)
				break;
		}

		if (flag == 1)
			cout << "UNSAFE\n";
		else
			cout << "SAFE\n";
	}

	return 0;
}