#include <bits/stdc++.h>
using namespace std;
int arr[10000000000];
void declaration()
{
    arr[0] = 1;
    arr[1] = 2;
}
void permutations(int x)
{
    arr[x] = arr[x - 1] + arr[x - 2];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    declaration();
    int t = 0;
    cin >> t;
    int n = 0;
    while (t--)
    {
        cin >> n;
        permutations(n);
        cout << arr[n] % 1000000007 << "\n";
    }
}