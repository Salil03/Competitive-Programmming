#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, q = 0, temp = 0;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        cout << distance(num, find(num, num + n, temp)) + 1 << "\n";
    }
}