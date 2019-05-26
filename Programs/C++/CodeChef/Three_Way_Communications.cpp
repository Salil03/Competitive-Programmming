#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0, r = 0;
    cin >> t;
    pair<int, int> chef = {0, 0}, sous = {0, 0}, head = {0, 0};
    while (t--)
    {
        cin >> r >> chef.first >> chef.second >> head.first >> head.second >> sous.first >> sous.second;
        if (sqrt(pow(chef.first - head.first, 2) + pow(chef.second - head.second, 2)) <= r)
        {
            if (sqrt(pow(chef.first - sous.first, 2) + pow(chef.second - sous.second, 2)) <= r || sqrt(pow(head.first - sous.first, 2) + pow(head.second - sous.second, 2)) <= r)
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }

        else if (sqrt(pow(chef.first - head.first, 2) + pow(chef.second - head.second, 2)) > r)
        {
            if (sqrt(pow(chef.first - sous.first, 2) + pow(chef.second - sous.second, 2)) <= r && sqrt(pow(head.first - sous.first, 2) + pow(head.second - sous.second, 2)) <= r)
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}