#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	float numerator = 0;
	float denominator = n*100;
	float temp;
	while(n--)
	{
		cin >> temp;
		numerator += temp;
	}
	cout <<  setprecision(5) << fixed << numerator/denominator*100;
}