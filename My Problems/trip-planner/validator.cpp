#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	registerValidation(argc, argv);
	int n = inf.readInt(1, 10000, "n");
	inf.readSpace();
	int m = inf.readInt(1, 100, "m");
	inf.readEoln();
	int x = inf.readInt(1, n, "x");
	inf.readSpace();
	int y = inf.readInt(1, n, "y");
	inf.readEoln();
	inf.readEof();
}