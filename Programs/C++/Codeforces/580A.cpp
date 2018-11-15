#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int counter = 1;
    int max_counter = -2;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i-1])
        {
            counter++;
        }
        else
        {
            max_counter = max(max_counter, counter);
            counter = 1;
        }
    }
    cout << max(max_counter, counter);
}