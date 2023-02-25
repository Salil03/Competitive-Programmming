#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;

#if defined(DEBUG)
#include "prettyprint.hpp"
#define dbga(x, n) cerr << "\n" \
                        << (#x) << " is " << pretty_print_array(x, n) << endl
#define dbg(x) cerr << "\n" \
                    << (#x) << " is " << x << endl
#endif

#if !defined(DEBUG)
#define dbga(x, n)
#define dbg(x)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution < lll>(low, high)(rng)
// uniform_real_distribution<double>(low, high)(rng)

typedef tree<lll, null_type, less<lll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<lll, lll>, null_type, less<pair<lll, lll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// gp_hash_table<int, int> table; unordered map

#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    vector<lll> arr(3002);
    vector<lll> ans(3002);
    while (t--)
    {
        lll n, k;
        cin >> n >> k;
        for (lll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        reverse(arr.begin(), arr.begin() + n);
        lll minima = INT_MAX;
        for (lll elf = 1; elf <= k; elf++)
        {
            ans[0] = arr[0] / elf;
            lll maximum = ans[0];
            lll minimum = ans[0];
            for (lll i = 1; i < n; i++)
            {
                if (ans[i - 1] == 0)
                {
                    ans[i] = 0;
                }
                else
                {
                    lll temp_k = arr[i] / ans[i - 1];
                    lll new_ans1 = INT_MIN, new_ans2 = INT_MIN, new_ans3 = INT_MIN;
                    lll diff1 = INT_MAX, diff2 = INT_MAX, diff3 = INT_MAX;
                    // dbg(temp_k);
                    if (temp_k > 0)
                    {
                        new_ans1 = arr[i] / temp_k;
                        if (new_ans1 > ans[i - 1])
                        {
                            if (new_ans1 > maximum)
                            {
                                diff1 = new_ans1 - minimum;
                            }
                            else
                            {
                                diff1 = 0;
                            }
                        }
                        else if (new_ans1 == ans[i - 1])
                        {
                            diff1 = 0;
                        }
                        else
                        {
                            if (new_ans1 < minimum)
                            {
                                diff1 = maximum - new_ans1;
                            }
                            else
                            {
                                diff1 = 0;
                            }
                        }
                    }
                    if (temp_k + 1 <= k)
                    {
                        new_ans2 = arr[i] / (temp_k + 1);
                        if (new_ans2 > ans[i - 1])
                        {
                            if (new_ans2 > maximum)
                            {
                                diff2 = new_ans2 - minimum;
                            }
                            else
                            {
                                diff2 = 0;
                            }
                        }
                        else if (new_ans2 == ans[i - 1])
                        {
                            diff2 = 0;
                        }
                        else
                        {
                            if (new_ans2 < minimum)
                            {
                                diff2 = maximum - new_ans2;
                            }
                            else
                            {
                                diff2 = 0;
                            }
                        }
                    }
                    if (temp_k - 1 > 0)
                    {
                        new_ans3 = arr[i] / (temp_k - 1);
                        if (new_ans3 > ans[i - 1])
                        {
                            if (new_ans3 > maximum)
                            {
                                diff3 = new_ans3 - minimum;
                            }
                            else
                            {
                                diff3 = 0;
                            }
                        }
                        else if (new_ans3 == ans[i - 1])
                        {
                            diff3 = 0;
                        }
                        else
                        {
                            if (new_ans3 < minimum)
                            {
                                diff3 = maximum - new_ans3;
                            }
                            else
                            {
                                diff3 = 0;
                            }
                        }
                    }
                    if (diff2 <= diff1 && diff2 <= diff3)
                    {
                        ans[i] = new_ans2;
                    }
                    else if (diff1 <= diff2 && diff1 <= diff3)
                    {
                        ans[i] = new_ans1;
                    }
                    else
                    {
                        ans[i] = new_ans3;
                    }
                    // dbg(new_ans1);
                    // dbg(diff1);
                    // dbg(new_ans2);
                    // dbg(diff2);
                    // dbg(new_ans3);
                    // dbg(diff3);
                    maximum = max(maximum, ans[i]);
                    minimum = min(minimum, ans[i]);
                }
            }
            // dbg(ans);
            minima = min(minima, *max_element(ans.begin(), ans.begin() + n) - *min_element(ans.begin(), ans.begin() + n));
        }
        cout << minima << "\n";
    }
}