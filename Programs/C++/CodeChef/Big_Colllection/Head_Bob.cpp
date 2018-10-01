#include <bits/stdc++.h>
using namespace std;
string check_nationality(string s)
{
    for (auto i : s)
    {
        if (i == 'I')
        {
            return "INDIAN";
        }
        else if (i == 'Y')
        {
            return "NOT INDIAN";
        }
    }
    return "NOT SURE";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0, n = 0;
    string head = "";
    cin >> t;
    while (t--)
    {
        cin >> n >> head;
        cout << check_nationality(head) << "\n";
    }
}