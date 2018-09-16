#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t = 0, n = 0, k = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        long long ans = 0;
        for (long long i = 1; i <= k; i++)
        {
            if (n % i > ans)
            {
                ans = n % i;
            }
        }
        cout << ans << "\n";
    }
}