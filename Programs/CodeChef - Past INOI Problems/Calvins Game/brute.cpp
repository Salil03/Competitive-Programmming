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
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;

/*
$alil03

URL: url

Solution Begins here
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lll n, k;
    cin >> n >> k;
    lll arr[n];
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lll right[n] = {0};
    right[k - 1] = 0;
    if (k < n)
    {
        right[k] = arr[k];
    }
    for (lll i = k + 1; i < n; i++)
    {
        right[i] = max(right[i - 1], right[i - 2]) + arr[i];
    }
    lll left[n] = {0};
    left[0] = 0;
    left[1] = left[0] + arr[0];
    for (int i = 2; i < n; i++)
    {
        left[i] = max(left[i - 1] + arr[i - 1], left[i - 2] + arr[i - 2]);
    }
    lll maximum = -1e11;
    for (int i = k - 1; i < n; i++)
    {
        maximum = max(maximum, right[i] + left[i]);
    }
    cout << maximum;
}