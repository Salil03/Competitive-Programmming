#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	int q = atoi(argv[2]);
	vector<int> a(n), x(q);
	for (int i = 0; i < n; i++)
	{
		a[i] = rnd.next(1, 1'000'000'000);
	}
	sort(a.begin(), a.end());
	int found = rnd.next(q / 2, q);
	for (int i = 0; i < found; i++)
	{
		x[i] = rnd.next(1, 1'000'000'000);
	}
	for (int i = found; i < q; i++)
	{
		x[i] = rnd.any(a);
	}
	shuffle(x.begin(), x.end());
	cout << n << " " << q << "\n";
	for (int i = 0; i < n - 1; i++)
	{
		cout << a[i] << " ";
	}
	cout << a[n - 1];
	cout << "\n";
	for (int i = 0; i < q; i++)
	{
		cout << x[i] << "\n";
	}
}