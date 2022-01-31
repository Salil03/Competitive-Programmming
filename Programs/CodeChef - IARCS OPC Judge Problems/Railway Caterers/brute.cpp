#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    FAST_IO
    int n, k;
    cin >> n >> k;
    vector<int> vec(n + 1, 0), sums(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> vec[i];
        sums[i] = sums[i - 1] + vec[i];
    }

    int ans = sums[k], sum = sums[k];
    for (int i = k + 1; i <= n; ++i)
    {
        if (sum + vec[i] < sums[i] - sums[i - k])
            sum = sums[i] - sums[i - k];
        else
            sum += vec[i];

        ans = max(sum, ans);
    }
    cout << ans << '\n';

    return 0;
}