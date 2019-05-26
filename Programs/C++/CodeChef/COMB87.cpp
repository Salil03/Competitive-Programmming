#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
void binary(int &n)
{
    int binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    n = binaryNumber;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l = 1;
	int r = 10;
	binary(r);
	cout << r;
}