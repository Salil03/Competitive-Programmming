#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	registerValidation(argc, argv);
	int n = inf.readInt(1, 1'000'00, "n");
	inf.readSpace();
	int q = inf.readInt(1, 1'000'00, "q");
	inf.readEoln();
	vector<int> a = inf.readInts(n, 1, 1'000'000'000, "a[i]");
	inf.readEoln();
	for (int i = 0; i < (int)a.size() - 1; i++)
	{
		ensuref(a[i] <= a[i + 1], "Array increasing at %d", i + 1);
	}
	for (int i = 0; i < q; i++)
	{
		inf.readInt(1, 1'000'000'000, "x[i]");
		inf.readEoln();
	}
	inf.readEof();
}