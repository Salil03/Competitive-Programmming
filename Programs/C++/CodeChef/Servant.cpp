#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0, n = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n < 10)
            cout << "What an obedient servant you are!"
                 << "\n";
        else
            cout << -1 << "\n";
    }
}