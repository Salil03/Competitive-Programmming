#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t = 0, n = 0, k = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        long long arr[k];
        for (long long i = 1; i <= k; i++)
        {
            arr[i - 1] = n % k;
        }
        cout << *max_element(arr, arr + k) << "\n";
    }
}