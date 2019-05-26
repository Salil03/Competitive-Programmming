#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> people;
    int x, y, z;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        people.push_back(make_pair(y + z, x));
    }
    sort(people.begin(), people.end());
    int total = people[0].first, total1 = people[n - 1].first + people[n - 1].second;
    for (int i = 0; i < n; i++)
    {
        total += people[i].second;
    }
    cout << max(total, total1);
    return 0;
}