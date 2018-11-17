#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    unsigned long long ans = 0;
    for(long long i = 0; i<n-1;i++)
    {
        ans |= arr[i];
    }
    ans &= arr[n-1];
    cout << ans;
}