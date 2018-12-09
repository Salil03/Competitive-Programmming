#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int m,n;
    cin>>m>>n;
    string a;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[j]=='B'&&a[j+1]=='G')
            {
                swap(a[j],a[j+1]);
                j++;
            }
        }
    }
    cout<<a;
}