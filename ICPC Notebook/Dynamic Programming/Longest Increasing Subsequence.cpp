//nlogn
int lis(int arr[], int N)
{
    int i;
    set<int> s;
    set<int>::iterator k;
    for (i = 0; i < N; i++)
    {
        if (s.insert(arr[i]).second)
        {
            k = s.find(arr[i]);

            k++;

            if (k != s.end())
                s.erase(k);
        }
    }
    // Note that set s may not contain actual LIS, but its size gives
    // us the length of LIS
    return s.size();
}