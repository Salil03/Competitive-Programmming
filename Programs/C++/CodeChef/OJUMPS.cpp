#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    unsigned long long t;
    cin >> t;
    if(t%6 == 1 || t%6 == 3 || t%6 == 0)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}