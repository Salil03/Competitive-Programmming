//OPTIMIZATIONS
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//OPTIMIZATIONS
#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << "\n" \
                      << (#x) << " is " << (x) << endl
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long MAXI = ULONG_MAX;

/*
$alil03

URL: url

Solution Begins here
*/

long long int minimum(long long int arr[], long long int x)
{
    if (arr[x] <= arr[x - 1])
    {
        if (arr[x] <= arr[x - 2])
        {
            return x;
        }
        else
        {
            return x - 2;
        }
    }
    if (arr[x - 1] < arr[x])
    {
        if (arr[x - 1] <= arr[x - 2])
        {
            return x - 1;
        }
        else
        {
            return x - 2;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long int a[n];
    long long int v[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int index = minimum(a, 2);
    v[index] = 1;
    for (int i = index + 1; i < n; i++)
    {
        if (v[i - 3] == 1 && v[i - 1] != 1 && v[i - 2] != 1)
        {
            v[minimum(a, i)] = 1;
        }
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            sum += a[i];
        }
    }
    cout << sum;
}