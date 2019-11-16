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

bool primes[10000];

void sieve()
{
	primes[2] = false;
	for (int i = 3; i < 10000; i++)
	{
		if (!(i & 1))
		{
			primes[i] = true;
		}
	}
	for (int i = 3; i < 10000; i++)
	{
		if (primes[i])
		{
			continue;
		}
		for (int j = i + 1; j < 10000; j++)
		{
			if (j % i == 0)
			{
				primes[j] = true;
			}
		}
	}
}

void construct_graph(vector<int> graph[])
{
	for (int i = 1000; i <= 9999; i++)
	{
		if (primes[i])
		{
			continue;
		}
		for (int j = 1; j <= 9; j += 2)
		{
			int num = i / 10 * 10 + j;
			if (!primes[num] && num != i)
			{
				graph[i].push_back(num);
			}
		}
		for (int j = 0; j <= 9; j++)
		{
			int num = i / 100 * 100 + j * 10 + i % 10;
			if (!primes[num] && num != i)
			{
				graph[i].push_back(num);
			}
		}
		for (int j = 0; j <= 9; j++)
		{
			int num = i / 1000 * 1000 + j * 100 + i % 100;
			if (!primes[num] && num != i)
			{
				graph[i].push_back(num);
			}
		}
		for (int j = 1; j <= 9; j++)
		{
			int num = j * 1000 + i % 1000;
			if (!primes[num] && num != i)
			{
				graph[i].push_back(num);
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	vector<int> graph[10005];
	sieve();
	construct_graph(graph);
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		bool visited[10005] = {0};
		int distance[10005] = {0};
		for (int i = 1; i < 10005; i++)
		{
			if (i == a)
			{
				distance[i] = 0;
			}
			else
			{
				distance[i] = -1;
			}
		}
		visited[a] = true;
		queue<int> q;
		q.push(a);
		while (!q.empty())
		{
			int s = q.front();
			q.pop();
			for (auto u : graph[s])
			{
				if (visited[u])
				{
					continue;
				}
				visited[u] = true;
				distance[u] = 1 + distance[s];
				q.push(u);
			}
		}
		cout << distance[b] << "\n";
	}
}