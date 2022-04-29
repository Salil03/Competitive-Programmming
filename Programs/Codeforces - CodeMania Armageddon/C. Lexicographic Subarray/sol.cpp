#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long uu;
typedef long long int lll;
typedef unsigned long long int uuu;
using namespace std;

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
#define cel(x, y) 1 + ((x - 1) / y)
const double PI = 3.141592653589793238463;
const int MOD = 1000000007;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
lll lim;
set<vector<lll>> presentSubstring(vector<lll> &arr, lll k)
{
    set<vector<lll>> st;
    lll n = arr.size();

    for (lll i = 0; i < n; i++)
    {
        vector<lll> s1;

        for (lll j = 0; j < k && i + j < n; j++)
        {
            s1.emplace_back(arr[i + j]);

            st.insert(s1);
        }
    }

    return st;
}

// Function to prlll the lexicographically
// smallest substring of length atmost k
// which is not present in given string s
vector<lll> smallestSubstring(vector<lll> &arr, lll k)
{
    set<vector<lll>> st;

    // All substrings of length atmost k
    // present in string s are stored in
    // this set
    st = presentSubstring(arr, k);

    lll index;

    // Loop to change length of substring
    for (lll len = 1; len <= k; len++)
    {

        // String with length=len which has
        // all characters as 'a'
        vector<lll> t(len, 0);

        while (true)
        {

            // If the substrings set does
            // not contain this string then
            // we have found the answer
            if (st.count(t) == 0)
            {
                return t;
            }

            index = len - 1;

            // Changing the likes of 'azz'
            // and 'daz' to 'baa' and 'dba'
            // respectively
            while (index >= 0 && t[index] == min((lll)50, lim - 1))
            {
                t[index] = 0;
                index--;
            }

            if (index >= 0)
                t[index]++;

            // Reached a string like 'zz'
            // or 'zzz' increase the length
            // of the substring
            else
                break;
        }
    }
    return {-1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n >> lim;
    vector<lll> arr(n);
    bool visited[lim];
    memset(visited, 0, sizeof(visited));
    for (lll i = 0; i < n; i++)
    {
        cin >> arr[i];
        visited[arr[i]] = 1;
    }
    for (lll i = 0; i < lim; i++)
    {
        if (!visited[i])
        {
            cout << i;
            return 0;
        }
    }
    if (lim == 1)
    {
        for (lll i = 0; i <= n; i++)
        {
            cout << 0 << " ";
        }
        return 0;
    }
    vector<lll> ans = smallestSubstring(arr, 10000000 / n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}