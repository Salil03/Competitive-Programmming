#include <iostream>
using namespace std;
int factorial(int x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}
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
        cout << factorial(n) << "\n";
    }
}