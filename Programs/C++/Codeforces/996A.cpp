#include<iostream>
using namespace std;
int greedy(int x)
{
	if(x >= 100)
	{
		return (x/100) + (greedy(x%100));
	}
	else if(x >= 20)
	{
		return (x/20) + (greedy(x%20));
	}
	else if(x >= 10)
	{
		return (x/10) + (greedy(x%10));
	}
	else if(x >= 5)
	{
		return (x/5) + (greedy(x%5));
	}
	else if(x >= 1)
	{
		return (x/1);
	}
}
int main()
{
	int n;
	cin >> n;
	cout << greedy(n);
}