#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while(cin >> n)
	{
		if(n == 0)
		{
			return 0;
		}
		int order[n];
		for(int i = 0; i<n; i++)
		{
			cin >> order[i];
		}
		stack<int> lane; int need = 1;
		bool state = true;
		for (int i = 0; i < n; i++) {
			while (!lane.empty() && lane.top() == need) {
				need++;
				lane.pop();
			}
			if (order[i] == need) {
				need++;
			} else if (!lane.empty() && lane.top() < order[i]) {
				state = false;
				break;
			} else {
				lane.push(order[i]);
			}
		}
		if (state) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}