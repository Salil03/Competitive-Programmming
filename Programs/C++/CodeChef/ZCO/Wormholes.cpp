#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, x, y, s, e;
    cin >> n >> x >> y;
    vector<pair<long long, long long>> contests;
    for (long long i = 0; i < n; i++)
    {
        cin >> s >> e;
        contests.push_back(make_pair(s, e));
    }
    vector<long long> v;
    vector<long long> w;
    for (long long i = 0; i < x; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    for (long long i = 0; i < y; i++)
    {
        cin >> s;
        w.push_back(s);
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    sort(contests.begin(), contests.end());
    int ans = INT_MAX;
    for (auto i : contests)
    {
        auto start = lower_bound(w.begin(), w.end(), i.second);
        auto end = upper_bound(v.begin(), v.end(), i.first) - 1;
        e = *start - *end + 1;
        if (e < 4)
        {
            continue;
        }
        if (ans > e)
        {
            ans = e;
        }
    }
    cout << ans;
}