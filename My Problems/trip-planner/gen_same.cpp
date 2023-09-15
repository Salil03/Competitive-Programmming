#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	registerGen(argc, argv, 1);
	// 	int min_n = atoi(argv[1]);
	// 	int max_n = atoi(argv[2]);
	// 	int n = rnd.next(min_n, max_n);
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	cout << n << " " << m << endl;
	int city = rnd.next(1, n);
	cout << city << " " << city << endl;
}