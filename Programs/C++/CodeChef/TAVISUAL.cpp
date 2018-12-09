#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n, c, q, u, v;

	    cin >> n >> c >>q;

	    for(int i = 1;i<=q; i++)
	     {
	        cin >> u >> v;

	        if (c < u || v < c) continue;

	        c = (u + v) - c;
	    }

	    cout << c << "\n";
	}
}
