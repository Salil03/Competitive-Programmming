#include<bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
const double PI  = 3.141592653589793238463;
const int MOD = 1000000007;

/*
$alil03

URL: https://www.codechef.com/COON2019/problems/CDRN03

Solution Begins here
*/
bool prime[1000004];

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}
int main()
{
	SieveOfEratosthenes(1000003);
	for(int i = 2; i<1000001; i++)
	{
		string s = to_string(i);
		if(prime[i])
		{
			cout << i << ", ";
			continue;
		}
		while(next_permutation(s.begin(), s.end()))
		{
			{
			if(prime[stoi(s)])
				cout << i << ", "
				break;
			}
		}
	}
}