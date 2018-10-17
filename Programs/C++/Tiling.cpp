#include<iostream>
using namespace std;
long long arr[1000004];
void ways_to_tile(long long x)
{
    for(int i = 2; i <= x; i++)
    {
        if(arr[i] == 0)
        {
            arr[i] = ((arr[i-1] % 1000000007) + (arr[i-2] % 1000000007))% 1000000007;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    arr[0] = 1;
    arr[1] = 1;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ways_to_tile(n);
        cout << arr[n] << "\n";
    }
}
