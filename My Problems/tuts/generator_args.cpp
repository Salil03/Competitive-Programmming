#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
	// 	int min_n = atoi(argv[1]);
	// 	int max_n = atoi(argv[2]);
	// 	int n = rnd.next(min_n, max_n);
	int n = atoi(argv[1]);
	cout << n << endl;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		a[i] = rnd.next(1, 1000000000);
	}
	sort(a.begin(), a.end());
	cout << a[0];
	for (int i = 1; i < n; i++)
	{
		cout << " " << a[i];
	}
	cout << endl;
	int q = rnd.next(1, 100000);
	cout << q << endl;
	vector<int> query(q);

	for (int i = 0; i < q; i++)
	{
		query[i] = rnd.next(-1 - n / 10, n);
	}

	for (int i = 0; i < q; i++)
	{
		if (query[i] <= 0)
			cout << rnd.next(1, 1000000000);
		else
			cout << a[query[i] - 1];
		if (i != q - 1)
			cout << endl;
	}

	return 0;
}