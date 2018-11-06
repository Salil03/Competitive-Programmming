#include <bits/stdc++.h>
using namespace std;
int arr[1004][804];
void calc_bino(int x, int s)
{
    if(s == 0 || s == x)
    {
        arr[x][s] == 1;
        return 1;
    }
    if(arr[x][s] == 0)
    {
        arr[x][s] == arr[x-1][s-1] + arr[x-1][s];
        return arr[x][s];
    }
    else
    {

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,r;
        cin >> n >> r;
        calc_bino(n,r);
        cout << arr[n][r] << "\n";
    }
}
