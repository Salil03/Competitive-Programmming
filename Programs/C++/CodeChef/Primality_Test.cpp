#include <bits/stdc++.h>
using namespace std;
string isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return "no";
    if (n <= 3)
        return "yes";

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return "no";

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return "no";

    return "yes";
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
        cin >> n, cout << isPrime(n) << "\n";
    }
}