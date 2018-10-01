#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, x, n;
    cin >> s >> x >> n;
    int day[n];
    int distance[n];
    for (int i = 0; i < n; i++)
    {
        cin >> day[i];
        cin >> distance[i];
    }
    int ans = 1;
    while (s > 0)
    {
        auto match = find(day, day + n, ans);
        if (match - day == ans - 1)
        {
            s -= distance[match - day];
        }
        else
        {
            s -= x;
        }
        ans++;
    }
    cout << ans;
}