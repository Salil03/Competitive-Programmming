#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << N / 2 + 1 << "\n";
	}
	return 0;
}