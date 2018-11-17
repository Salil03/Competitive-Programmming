#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, k;
    cin >> t >> k;
    while (t--)
    {
        long long n;
        cin >> n;
        long long temp = 0;
        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            cin >> temp;
            ans += temp;
        }
        if (ans > k)
        {
            cout << "FAILURE\n";
        }
        else
        {
            cout << "SUCCESS\n";
        }
    }
}