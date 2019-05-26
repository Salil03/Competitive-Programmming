#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0, m = 0, n = 0, temp = 0;
    cin >> t;
    vector<int> n_vec;
    for (int i = 1; i <= t; i++)
    {
        n_vec.clear();
        temp = 0;
        n = 0;
        m = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            n_vec.push_back(temp);
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> temp;
            if (count(n_vec.begin(), n_vec.end(), temp))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}