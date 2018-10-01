#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y, s, e;
    cin >> n >> x >> y;
    vector<pair<int, int>> contests;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        contests.push_back(make_pair(s, e));
    }
    vector<int> v;
    vector<int> w;
    for (int i = 0; i < x; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < y; i++)
    {
        cin >> s;
        w.push_back(s);
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    vector<int> final;
    for (auto i : contests)
    {
        auto start = lower_bound(w.begin(), w.end(), i.second);
        auto end = upper_bound(v.begin(), v.end(), i.first);
        end--;
        e = *start - *end;
        final.push_back(e + 1);
    }
    cout << *min_element(final.begin(), final.end());
}