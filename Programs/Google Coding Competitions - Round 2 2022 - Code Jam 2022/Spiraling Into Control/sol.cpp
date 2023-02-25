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

lll matrix[10000][10000];
lll n, k;
void prlllSpiral(lll size)
{

    // Create row and col
    // to traverse rows and columns
    lll row = 0, col = 0;

    lll boundary = size - 1;
    lll sizeLeft = size - 1;
    lll flag = 1;

    // Variable to determine the movement
    // r = right, l = left, d = down, u = upper
    char move = 'r';

    // Array for matrix

    for (lll i = 1; i < size * size + 1; i++)
    {

        // Assign the value
        matrix[row][col] = i;

        // switch-case to determine the next index
        switch (move)
        {

        // If right, go right
        case 'r':
            col += 1;
            break;

        // if left, go left
        case 'l':
            col -= 1;
            break;

        // if up, go up
        case 'u':
            row -= 1;
            break;

        // if down, go down
        case 'd':
            row += 1;
            break;
        }

        // Check if the matrix
        // has reached array boundary
        if (i == boundary)
        {

            // Add the left size for the next boundary
            boundary += sizeLeft;

            // If 2 rotations has been made,
            // decrease the size left by 1
            if (flag != 2)
            {

                flag = 2;
            }
            else
            {

                flag = 1;
                sizeLeft -= 1;
            }

            // switch-case to rotate the movement
            switch (move)
            {

            // if right, rotate to down
            case 'r':
                move = 'd';
                break;

            // if down, rotate to left
            case 'd':
                move = 'l';
                break;

            // if left, rotate to up
            case 'l':
                move = 'u';
                break;

            // if up, rotate to right
            case 'u':
                move = 'r';
                break;
            }
        }
    }
}

// vector<lll> ans;

// bool dfs(lll node, lll length, lll target, vector<lll> adj[])
// {
//     if (length > k)
//     {
//         return false;
//     }
//     if (node == target && length == k)
//     {
//         return true;
//     }
//     else if (node == target && length != k)
//     {
//         return false;
//     }
//     for (auto u : adj[node])
//     {
//         ans.emplace_back(u);
//         if (!dfs(u, length + 1, target, adj))
//         {
//             ans.pop_back();
//         }
//         else
//         {
//             return true;
//         }
//     }
//     return false;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    lll t;
    cin >> t;
    for (lll test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        cin >> n >> k;
        vector<lll> adj[n * n + 1];
        vector<lll> adj2[n * n + 1];
        prlllSpiral(n);
        for (lll i = 0; i < n; i++)
        {
            for (lll j = 0; j < n; j++)
            {
                if (i > 0)
                {
                    if (matrix[i - 1][j] > matrix[i][j])
                    {
                        adj[matrix[i][j]].emplace_back(matrix[i - 1][j]);
                        adj2[matrix[i - 1][j]].emplace_back(matrix[i][j]);
                    }
                }
                if (j > 0)
                {
                    if (matrix[i][j - 1] > matrix[i][j])
                    {
                        adj[matrix[i][j]].emplace_back(matrix[i][j - 1]);
                        adj2[matrix[i][j - 1]].emplace_back(matrix[i][j]);
                    }
                }
                if (i < n - 1)
                {
                    if (matrix[i + 1][j] > matrix[i][j])
                    {
                        adj[matrix[i][j]].emplace_back(matrix[i + 1][j]);
                        adj2[matrix[i + 1][j]].emplace_back(matrix[i][j]);
                    }
                }
                if (j < n - 1)
                {
                    if (matrix[i][j + 1] > matrix[i][j])
                    {
                        adj[matrix[i][j]].emplace_back(matrix[i][j + 1]);
                        adj2[matrix[i][j + 1]].emplace_back(matrix[i][j]);
                    }
                }
            }
        }

        bool B[n * n + 1][k + 1];

        // Create B_0
        for (int i = 1; i <= n * n; i++)
        {
            B[i][0] = false;
        }
        B[1][0] = true;

        // Perform the k repetitions
        for (int i = 1; i <= k; i++)
        {
            // Copy B (B_i) to PB (B_{i-1}) and initialize B
            for (int j = 1; j <= n * n; j++)
            {
                B[j][i] = false;
            }
            for (int j = 1; j <= n * n; j++)
            {
                if (B[j][i - 1])
                {
                    // There is a walk from s to j of length i-1...
                    for (auto u : adj[j])
                    {
                        // ...and an edge from j to E[j][l]...
                        B[u][i] = true;
                        // ...so there is a walk of length i from s to E[j][l]
                    }
                }
            }
        }
        // Now B = B_k

        if (!B[n * n][k])
        {
            // There is a walk of length k from s to a
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            vector<pair<lll, lll>> ans;
            lll curr = n * n, curr2 = k - 1;
            while (curr2 >= 0)
            {
                for (auto u : adj2[curr])
                {
                    if (B[u][curr2])
                    {
                        if (curr - u > 1)
                        {
                            ans.emplace_back(make_pair(u, curr));
                        }
                        curr = u;
                        curr2 -= 1;
                        break;
                    }
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (auto u : ans)
            {
                cout << u.first << " " << u.second << "\n";
            }
        }
    }
}
