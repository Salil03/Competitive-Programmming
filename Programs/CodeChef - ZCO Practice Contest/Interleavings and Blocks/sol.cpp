#include "bits/stdc++.h"
using namespace std;

typedef long long int lll;

lll n, m, k;
lll dp[105][105][205][2];
vector<lll> arra, arrb;
lll MOD = 100 * 100 * 100 * 100 + 7;

lll ways(lll ai, lll bi, lll blocks_made, lll last)
{

	/*
	This function returns the number of possible ways to make an array of exactly k blocks, if:
		* I have already taken the first 'ai' values from array A, and
		* I have already taken the first 'bi' values from array B, and 
		* I have made 'blocks_made' blocks so far, and
		* last is 0 if the last value I took was from array A, and 1 if the last value was from array B
	*/

	// if this state has already been calculated, then just return the calculated value
	if (dp[ai][bi][blocks_made][last] != -1)
	{
		return dp[ai][bi][blocks_made][last];
	}

	// if n numbers from array A have been taken and m numbers from array B have been taken, then all the numbers have been taken!
	// so if, having taken all the numbers, I have made exactly k blocks, then there is one way to my answer
	// if i have not made k blocks, then there are 0 ways ending like this
	if (ai == n && bi == m)
	{
		return dp[ai][bi][blocks_made][last] = (blocks_made == k);
	}

	// otherwise, make a result variable to store my answer
	lll res = 0;

	// if last is 0, then the last number I took was from array A, and if it is 1, then the last number I took was from array B.
	// this code recovers the last number I took, and stores it in 'las'
	lll las;
	if (last == 0)
		las = arra[ai - 1];
	else
		las = arrb[bi - 1];

	// if I have taken less than n values from array A, I can still take at least another value from array A
	if (ai < n)
	{
		// if the next value from array A is the same as the last value I took
		if (arra[ai] == las)
		{
			// then, add the number of ways to get exactly k blocks made having:
			// 	* taken 1 more value from array A, (so ai+1),
			//  * no more values from array B, (so bi),
			//  * the same number of blocks made (as the last number is the same as the next number, an additional block is not created), (so blocks_made)
			//  * now, the last number I took was from array A, (so 0)
			res += ways(ai + 1, bi, blocks_made, 0);
		}
		// but if the next value from array A is not the same as the last value I took
		else
		{
			// then, add the number of ways to get exactly k blocks made having:
			// 	* taken 1 more value from array A, (so ai+1),
			//  * no more values from array B, (so bi),
			//  * one more block is made (as the last number is the not the same as the next number, another block is created), (so blocks_made+1)
			//  * now, the last number I took was from array A, (so 0)
			res += ways(ai + 1, bi, blocks_made + 1, 0);
		}
		res = res % MOD;
	}
	// if I have taken less than m values from array B, I can still take at least another value from array B
	if (bi < m)
	{
		// if the next value from array B is the same as the last value I took
		if (arrb[bi] == las)
		{
			// then, add the number of ways to get exactly k blocks made having:
			//  * no more values from array A, (so ai),
			//  * taken 1 more value from array B, (so bi+1),
			//  * the same number of blocks made (as the last number is the same as the next number, an additional block is not created), (so blocks_made)
			//  * now, the last number I took was from array B, (so 1)
			res += ways(ai, bi + 1, blocks_made, 1);
		}
		// but if the next value from array B is not the same as the last value I took
		else
		{
			// then, add the number of ways to get exactly k blocks made having:
			//  * no more values from array A, (so ai),
			//  * taken 1 more value from array B, (so bi+1),
			//  * one more block is made (as the last number is the not the same as the next number, another block is created), (so blocks_made+1)
			//  * now, the last number I took was from array B, (so 1)
			res += ways(ai, bi + 1, blocks_made + 1, 1);
		}
		res = res % MOD;
	}
	// now, I store my result in the dp table so I don't recalculate it again later, and return from the function
	return dp[ai][bi][blocks_made][last] = res % MOD;
}

void solve()
{
	// first clear the two vectors, in case there are numbers from a previous testcase
	arra.clear();
	arrb.clear();
	// here, reset the entire dp-table for future reuse as needed
	for (lll i = 0; i < 105; i++)
	{
		for (lll j = 0; j < 105; j++)
		{
			for (lll k = 0; k < 205; k++)
			{
				dp[i][j][k][0] = -1;
				dp[i][j][k][1] = -1;
			}
		}
	}
	// input the values for n, m, k
	cin >> n >> m >> k;
	// input the arrays themselves
	for (lll i = 0; i < n; i++)
	{
		lll x;
		cin >> x;
		arra.push_back(x);
	}
	for (lll i = 0; i < m; i++)
	{
		lll x;
		cin >> x;
		arrb.push_back(x);
	}
	// the first value taken must be either the first value in array A or the first value in array B:
	cout << (ways(1, 0, 1, 0) + ways(0, 1, 1, 1)) % MOD << endl;
}

int main()
{

	// to solve each test case
	lll t;
	cin >> t;
	while (t--)
		solve();
}
