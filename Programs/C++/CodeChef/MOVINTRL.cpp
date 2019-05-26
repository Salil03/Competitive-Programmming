#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i=0; i<t; i++)
	{
	    int c,n,k;
	    cin >> c >> n >> k;
	    int s[n], e[n];
	    for (int i=0; i<n; i++)
	    {
	        cin >> s[i];
	        cin >> e[i];
	    }
	    if (k==0)
	    {
	        bool t = true;
	        for (int i=0; i<n; i++){
	            for (int j=0; j<i; j++){
	                if (s[j] <= s[i] && e[j] >= s[i]) t = false;
	                if (s[i] <= s[j] && e[i] >= s[j]) t = false;
	            }
	        }
	        if (t) cout << "Good\n";
	        else cout << "Bad\n";
	    }
	}
	return 0;
}