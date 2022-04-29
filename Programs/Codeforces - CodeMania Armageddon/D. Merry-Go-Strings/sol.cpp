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

vector<lll> dp(400003, -1);
vector<lll> match;
void lps_func(string txt, vector<lll> &Lps)
{
    Lps[0] = 0;
    lll len = 0;
    lll i = 1;
    while (i < (lll)txt.length())
    {
        if (txt[i] == txt[len])
        {
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else
        {
            if (len == 0)
            {
                Lps[i] = 0;
                i++;
                continue;
            }
            else
            {
                len = Lps[len - 1];
                continue;
            }
        }
    }
}

void KMP(string pattern, string text)
{
    lll n = text.length();
    lll m = pattern.length();
    vector<lll> Lps(m);
    lps_func(pattern, Lps); // This function constructs the Lps array.

    lll i = 0, j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        } // If there is a match continue.
        if (j == m)
        {
            match.emplace_back(i - m); // if j==m it is confirmed that we have found the pattern and we output the index
                                       // and update j as Lps of last matched character.
            j = Lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {               // If there is a mismatch
            if (j == 0) // if j becomes 0 then simply increment the index i
                i++;
            else
                j = Lps[j - 1]; // Update j as Lps of last matched character
        }
    }
}
lll r;

lll recur(lll curr, lll rem, lll n)
{
    lll ans = 0;
    if (rem == 0 && curr == 0)
    {
        return 1;
    }
    if (rem == 1)
    {
        return 1;
    }
    for (lll i = 0; i < n; i++)
    {
        lll new_curr = (curr - i) % n;
        if (new_curr < 0)
        {
            new_curr += n;
        }
        ans += recur(new_curr, rem - 1, n);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = s + s;
    s.pop_back();
    KMP(t, s);
    cin >> r;
    lll sum = 0;
    for (auto i : match)
    {
    }
    cout << sum;
}