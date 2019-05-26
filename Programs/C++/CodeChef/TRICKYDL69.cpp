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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long int powers[26] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864};
		for(int i = 0; i<26; i++)
		{
			powers[i]--;
		}
		long long int A;
		cin >> A;
		bool done = false;
		for(int i = 1; i<=26; i++)
		{
			if(A*i - powers[i-1] < 0)
			{
				cout << i-1 << " ";
				done = true;
				break;
			}
		}
		if(!done)
		{
			cout << 26 << " ";
		}
	}
}