#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
int sum(int x)
{
    int ans = 0;
    for(int i: primes)
    {
        if(i > x)
        {
            return ans;
        }
        ans += i;
    }
    return ans;
}
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.emplace_back(p); 
} 
int recur(int x)
{
    if(x == 0 || x == 1 || x==2)
    {
        return 0;
    }
    if(prime[x-1])
    {
        return recur(x-1) + sum(x);
    }
    else
    {
        
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        SieveOfEratosthenes(n-1);
        for(int i:primes)
        {
            cout << i << "\n";
        }
    }
}