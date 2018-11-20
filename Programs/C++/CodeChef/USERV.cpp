#include<bits/stdc++.h>
using namespace std;
unsigned long long arr[200004];
vector<unsigned long long> primes;
void f(unsigned long long x)
{
    unsigned long long ans = 0;
    unsigned long long c = lower_bound(primes.begin(), primes.end(), x)  - primes.begin();
    for(unsigned long long i = 1; i<= c; i++)
    {
        ans += primes[i-1] * (c-i+1);
    }
    arr[x] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(unsigned long long i = 2; i<200004; i++)
    {
        if(arr[i]) continue;
        else
        {
            primes.emplace_back(i);
            for(unsigned long long j = 2*i; j<200004; j+=i)
            {
                arr[j] = i;
            }   
        }
    }
    unsigned long long t;
    cin >> t;
    for(unsigned long long i = 2; i<=200004; i++)
    {
        f(i);
    }
    while(t--)
    {
        unsigned long long n;
        cin >> n;
        cout << "v01d#"<< *lower_bound(arr, arr+n, n) << "\n";
    }
}