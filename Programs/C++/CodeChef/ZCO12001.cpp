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
	int n;
	cin >> n;
	string s = "";
	int maximum_depth = -INF, depth = 0, index_depth = 0;
	for(int i = 0; i<n; i++)
	{
		int temp;
		cin >> temp;
		if(temp == 1)
		{
			depth++;
			if(depth > maximum_depth)
			{
				maximum_depth = depth;
				index_depth = i;
			}
			s += '1';
		}
		else
		{
			depth--;
			s += '2';
		}
	}
	int maximum_length = -INF, len = 0, index_length = 0, start = 0;
	depth = 0;
	bool counting = false;
	for(int i = 0; i<n; i++)
	{
		if(counting)
		{
			if(s[i] == '1')
			{
				depth++;
			}
			else if(s[i] == '2')
			{
				depth--;
			}
			len++;
			if(depth == 0)
			{
				counting = false;
				if(len > maximum_length)
				{
					maximum_length = len;
					index_length = start;
				}
			}
		}
		else if(depth == 0)
		{
			counting = true;
			start = i;
			len = 1;
			depth++;
		}
	}
	cout << maximum_depth << " " << index_depth+1 << " " << maximum_length << " " << index_length+1;
}