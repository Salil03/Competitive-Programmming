// you can use includes, for example:
#include <bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

long long int solution(vector<long long int> &A)
{
    long long int n = A.size();
    long long int maximum = 0;
    vector<long long int> subset1, subset2, subset3;
    for (int num1 = 0; num1 < (1 << n); num1++)
    {
        subset1.clear();
        long long int curr_sum1 = 0;
        for (int j = 0; j < n; j++)
        {
            if ((num1 >> j) & 1)
            {
                curr_sum1 += A[j];
            }
            else
            {
                subset1.push_back(A[j]);
            }
        }
        long long int size1 = subset1.size();
        for (long long int num2 = 0; num2 < (1 << size1); num2++)
        {
            subset2.clear();
            long long int curr_sum2 = 0;
            for (int j = 0; j < size1; j++)
            {
                if ((num2 >> j) & 1)
                {
                    curr_sum2 += subset1[j];
                }
                else
                {
                    subset2.push_back(subset1[j]);
                }
            }
            long long int size2 = subset2.size();
            for (long long int num3 = 0; num3 < (1 << size2); num3++)
            {
                subset3.clear();
                long long int curr_sum3 = 0;
                for (int j = 0; j < size2; j++)
                {
                    if ((num3 >> j) & 1)
                    {
                        curr_sum3 += subset2[j];
                    }
                    else
                    {
                        subset3.push_back(subset2[j]);
                    }
                }
                long long int size3 = subset3.size();
                for (long long int num4 = 0; num4 < (1 << size3); num4++)
                {
                    long long int curr_sum4 = 0;
                    for (int j = 0; j < size3; j++)
                    {
                        if ((num4 >> j) & 1)
                        {
                            curr_sum4 += subset3[j];
                        }
                    }
                    if (curr_sum1 == curr_sum2 && curr_sum1 == curr_sum3 && curr_sum1 == curr_sum4)
                    {
                        maximum = max(maximum, curr_sum1);
                    }
                }
            }
        }
    }

    return maximum;
}

int main()
{
    vector<long long int> A = {2, 2, 2, 2, 2, 10, 10, 10};
    cout << solution(A);
}
