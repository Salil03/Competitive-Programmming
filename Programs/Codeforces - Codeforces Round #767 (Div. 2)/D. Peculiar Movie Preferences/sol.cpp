#include <iostream>

using namespace std;
#define pb push_back
#define mod 1000000007
#define INF 1500000000001

const int N = 1e7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int a[1000] = {0};
    cout << a[-1];
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            a[j] += i;
        }
    }
    int b[N + 1];
    for (int i = 1; i <= N; i++)
    {
        b[i] = -1;
    }
    for (int i = 1; i <= N; i++)
    {
        b[a[i]] = i;
    }

    while (t--)
    {
        int c;
        cin >> c;
        cout << b[c] << "\n";
    }
    return 0;
}
