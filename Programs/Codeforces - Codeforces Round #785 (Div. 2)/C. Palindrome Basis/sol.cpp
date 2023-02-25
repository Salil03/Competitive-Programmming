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

// from gfg

lll createPalindrome(lll input, lll b, bool isOdd)
{
    lll n = input;
    lll palin = input;

    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;

    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
vector<lll> palin;
// Function to prlll decimal palindromic number
void generatePalindromes(lll n)
{
    lll number;

    // Run two times for odd and even length palindromes
    for (lll j = 0; j < 2; j++)
    {
        // Creates palindrome numbers with first half as i.
        // Value of j decided whether we need an odd length
        // of even length palindrome.
        lll i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            palin.emplace_back(number);
            i++;
        }
    }
}

lll table[40005];

void count(vector<lll> S, lll m, lll n)
{
    // Base case (If given value is 0)
    table[0] = 1;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for (lll i = 0; i < m; i++)
    {
        for (lll j = S[i]; j <= n; j++)
        {
            table[j] += table[j - S[i]];
            table[j] %= MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll MAX = 40000;
    generatePalindromes(MAX);
    sort(palin.begin(), palin.end());
    memset(table, 0, sizeof(table));
    count(palin, palin.size(), 40000);
    lll t;
    cin >> t;
    while (t--)
    {
        lll n;
        cin >> n;
        cout << table[n] % MOD << "\n";
    }
}