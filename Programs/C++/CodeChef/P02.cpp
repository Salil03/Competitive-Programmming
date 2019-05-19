#include <bits/stdc++.h>
using namespace std;
long long dp[104];
int lis(string x, string y, int n, int m)
{
  if (n == 1 || m == 1)
  {
    return 1;
  }
  if (x[n - 1] == y[m - 1])
  {
    return lis(x, y, n - 1, m - 1);
  }
  else
  {
    max(lis(x, y, n - 1, m), lis(x, y, n, m - 1));
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string x, y;
  cin >> x >> y;
  int n = x.length(), m = y.length();
  cout << lis(x, y, n, m);
}