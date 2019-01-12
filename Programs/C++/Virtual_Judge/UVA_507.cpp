#include<bits/stdc++.h>
using namespace std;

int b, s, n[30000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> b;
    for(int i = 1; i <= b; i++)
     {
        cin >> s;
        n[0] = 0;
        for(int j = 1; j < s; j++)
        {
        	cin >> n[j];
        }
        int a = 0, b = 0, c = 0, sum = 0, max = 0;
        for(int j = 1; j < s; j++)
        {
            sum += n[j];
            if(sum > max || (sum == max && j - a > b - c))
            {
                max = sum;
                b = j;
                c = a;
            }
            if(sum < 0)
            {
                a = j;
                sum = 0;
            }
        }
        if(max > 0)
        {
        	cout << "The nicest part of route " << i << " is between stops " << c+1 << " and " << b+1 << "\n";
        }
        else
        {
        	cout << "Route " << i << " has no nice parts\n";
        }
    }
}