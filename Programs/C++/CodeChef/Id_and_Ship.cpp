#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    char x;
    while (t--)
    {
        cin >> x;
        if (x == 'B' || x == 'b')
        {
            cout << "BattleShip\n";
        }
        else if (x == 'C' || x == 'c')
        {
            cout << "Cruiser\n";
        }
        else if (x == 'D' || x == 'd')
        {
            cout << "Destroyer\n";
        }
        else if (x == 'F' || x == 'f')
        {
            cout << "Frigate\n";
        }
    }
}