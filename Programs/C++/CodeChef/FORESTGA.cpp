#include<bits/stdc++.h>
using namespace std;
bool can_cut(unsigned long long int months, unsigned long long int limit, unsigned long long int height, unsigned long long int n, pair<unsigned long long int,unsigned long long int> arr[])
{
    unsigned long long int sum = 0;
    for(unsigned long long int i = 0; i<n; i++)
    {
        if(arr[i].first + months*arr[i].second >= limit)
        {
            sum += arr[i].first + months*arr[i].second;
        }
    }
    if(sum >= height)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    unsigned long long int n,w,l;
    cin >> n >> w >> l;
    pair<unsigned long long int ,unsigned long long int> arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    unsigned long long int low = -1;
    unsigned long long int high = 1000000000000000000;
    while(high - low > 1)
    {
        unsigned long long int mid = (low+high)/2;
        if(can_cut(mid, l, w, n, arr))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout << high;
}