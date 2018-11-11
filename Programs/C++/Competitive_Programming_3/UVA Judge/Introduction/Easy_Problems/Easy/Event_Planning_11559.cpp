#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,n,k;
    cin >> a >> n >> k;
    int arr[k] = {0};
    for(int i = 0; i<a; i++)
    {
        for(int j = 0; j<k; j++)
        {
            if(arr[j] < n)
            {
                arr[j]++;
                break;
            }
            else
            {
                arr[j] = 0;
            }
        }
    }
    for(int i = 0; i<k; i++)
    {
        cout << arr[i] << " ";
    }
}