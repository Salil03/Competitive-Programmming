#include<bits/stdc++.h>
    //#define watch(x) cout << (#x) << " is " << x << "\n";
    using namespace std;
    int main()
    {
    	ios_base::sync_with_stdio(false); //used to speedup I/O
    	cin.tie(0);//used to speedup I/O
    	cout.tie(0);//used to speedup I/O
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
    		sort(arr, arr+n, greater<int>());
    		int ans = 0;
    		for(int i = 0; i<n-1; i++)
    		{
    			//watch(i);
    			if(arr[i] != arr[i+1])
    			{
    				for(int j = i+1; j<n; j++)
    				{
    					arr[j] += arr[i] - arr[i+1];
    					ans++;
    				}
    			}
    		}
    		cout <<"answer is " <<  ans << "\n";
    	}
    }