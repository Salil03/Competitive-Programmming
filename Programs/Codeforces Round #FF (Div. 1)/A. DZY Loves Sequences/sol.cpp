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
const int INF = 0x3f3f3f3f;

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int maximum = 1;
	int left = 0, right = 0, length = 0;
	bool changed = 0;
	while (left <= right && right < n)
	{
		if (left == right)
		{
			right++;
			length = 1;
			changed = false;
			continue;
		}
		if (arr[right] > arr[left])
		{
			right++;
			length++;
		}
		else if (arr[right] <= arr[left] && changed)
		{
			right--;
			left++;
			length -= 2;
		}
		else if (arr[right] <= arr[left] && !changed)
		{
			changed = true;
			right++;
			length++;
		}
		maximum = max(maximum, length);
	}
	cout << maximum;
}