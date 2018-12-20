#include<bits/stdc++.h>
using namespace std;
int print2largest(int arr[], int arr_size)
{
    int i, first, second;


    first = second = INT_MIN;
    for (i = 0; i < arr_size ; i ++)
    {
        /* If current element is smaller than first
           then update both first and second */
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }

        /* If arr[i] is in between first and
           second then update second  */
        else if (arr[i] > second && arr[i] != first)
            second = arr[i];
    }
    return second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int ans = 0;
	vector<int> elements;
	int maximum = 0, temp_sum = 0;
	for(int i = 0; i<n; i++)
	{
		int maximum = *max_element(arr, arr+n);
		if(maximum == arr[i])
		{
			maximum =  print2largest(arr, n);
		}
		for(int j = 0; j<n; j++)
		{
			if(maximum == arr[j])
			{
				cout << "here";
				continue;
			}
			else
			{
				temp_sum += arr[j];
			}
		}
		if(temp_sum == maximum)
		{
			ans++;
			elements.emplace_back(i);
		}
	}
	cout << ans << "\n";
	for(int i: elements)
	{
		cout << i << " ";
	}
}