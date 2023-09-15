// you can use includes, for example:
#include <bits/stdc++.h>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool check(vector<int> &A, int num)
{
    int n = A.size();
    if (A[n - 1] - A[0] <= num)
    {
        return true;
    }
    int idx1 = (upper_bound(A.begin(), A.end(), A[0] + num) - A.begin()) - 1;
    if (A[n - 1] - A[idx1 + 1] <= num)
    {
        return true;
    }
    int idx2 = (upper_bound(A.begin() + idx1 + 1, A.end(), A[idx1 + 1] + num) - A.begin()) - 1;
    if (A[n - 1] - A[idx2 + 1] <= num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(vector<int> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    int low = 0, high = A[n - 1] - A[0], ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(A, mid))
        {
            ans = mid;
            high = ans - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {11, 5, 3, 12, 6, 8, 1, 7, 4};
    vector<int> B = {10, 14, 12, 1000, 11, 15, 13, 1};
    vector<int> C = {4, 5, 7, 10, 10, 12, 12, 12};
    vector<int> D = {5, 10, 10, 5, 5};
    cout << solution(D);
}
