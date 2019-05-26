#include <bits/stdc++.h>
using namespace std;
vector<long int> v;
vector<long int> final;
int block(long int x)
{
    int ans = 0;
    while (x > 0)
    {
        v.push_back(x % 2);
        x = x / 2;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            final.emplace_back(i);
            ans += i+1;
        }
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin >> n >> k;
	long long temp = block(n);
    if(temp < k)
    {
        cout << "NO";
        return 0;
    }
    for(int i: final)
    {
        cout << i << "\n";
    }
}