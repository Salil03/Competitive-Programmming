#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << x << "\n";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++)
        {
            cin >> arr[i];
        }
        bool stop = false;
        while(stop == false)
        {
            bool stop = true;
            for(int i = 0; i<n-1; i++)
            {
                if(arr[i] >= arr[i+1]+1)
                {
                    cout << "here";
                    arr[i] ^= arr[i+1];
                    arr[i+1] ^= arr[i];
                    arr[i] ^= arr[i+1];
                    stop = false;
                }
            }            
        }
        for(int i:arr)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}