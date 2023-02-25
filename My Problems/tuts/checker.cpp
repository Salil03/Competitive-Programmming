#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	// This command initializes checker environment.
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	int q = inf.readInt();
	vector<int> a = inf.readInts(n);
	vector<int> x(q);
	for (int i = 0; i < q; i++)
	{
		x[i] = inf.readInt();
	}
	vector<int> pa, ja;
	while (!ans.seekEof())
	{
		ja.push_back(ans.readInt(-1, n, "Jury query output"));
		if (ja.back() == 0)
		{
			quitf(_fail, "Integer parameter [name=Jury query output] equals to 0, violates the range [1, %d]", n);
		}
	}
	if ((int)ja.size() != q)
	{
		quitf(_fail, "Number of integers in jury output is wrong: expected = %d, found = %d", q, (int)ja.size());
	}
	while (!ouf.seekEof())
	{
		pa.push_back(ouf.readInt(-1, n, "query output"));
		if (pa.back() == 0)
		{
			quitf(_wa, "Integer parameter [name=query output] equals to 0, violates the range [1, %d]", n);
		}
	}
	if ((int)pa.size() != q)
	{
		quitf(_wa, "Number of integers in participant output is wrong: expected = %d, found = %d", q, (int)pa.size());
	}
	for (int i = 0; i < q; i++)
	{
		if (ja[i] == -1)
		{
			if (binary_search(a.begin(), a.end(), x[i]))
			{
				quitf(_fail, "%dth jury output is wrong: %d exists in array a", i + 1, x[i]);
			}
			else if (pa[i] != -1)
			{
				quitf(_wa, "%dth integer is wrong: expected = %d, found = %d", i + 1, -1, pa[i]);
			}
		}
		else
		{
			if (a[ja[i] - 1] != x[i])
			{
				quitf(_fail, "%dth jury output is wrong: a[%d] != x[%d]", i + 1, ja[i], i + 1);
			}
			else if (pa[i] == -1 || a[pa[i] - 1] != x[i])
			{
				quitf(_wa, "%dth integer is wrong: one of the expected answers = %d, found = %d", i + 1, ja[i], pa[i]);
			}
		}
	}
	quitf(_ok, "All queries have correct output\n");
}