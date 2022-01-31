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

/*
$alil03

URL: url

Solution Begins here
*/

//code from geeksforgeeks
lll _mergeSort(lll arr[], lll temp[], lll left, lll right);
lll merge(lll arr[], lll temp[], lll left, lll mid, lll right);

lll mergeSort(lll arr[], lll array_size)
{
	lll temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

lll _mergeSort(lll arr[], lll temp[], lll left, lll right)
{
	lll mid, inv_count = 0;
	if (right > left)
	{
		mid = (right + left) / 2;

		inv_count = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

lll merge(lll arr[], lll temp[], lll left,
		  lll mid, lll right)
{
	lll i, j, k;
	lll inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	lll t;
	cin >> t;
	while (t--)
	{
		lll n, q;
		cin >> n >> q;
		lll arr[n];
		for (lll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		while (q--)
		{
			lll k;
			cin >> k;
			lll final[n];
			for (lll i = 0; i < n; i++)
			{
				final[i] = arr[i] ^ k;
			}
			cout << mergeSort(final, n) << "\n";
		}
	}
}