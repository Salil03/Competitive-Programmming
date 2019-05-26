#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector <pair <int , int> > lower; // pair is used to store value and index
        vector <pair <int , int> > upper; // pair is used to store value and index
        int points[n]; // used to store final points
        for (int i = 0 ; i < n ; i++)
        {
            int a , b;
            cin >> a >> b;
            lower.push_back(make_pair(a , i));
            upper.push_back(make_pair(b , i));
            points[i] = 0; // fill all elements with zero
        }
        sort (lower.rbegin() , lower.rend()); //sort in descending order. Reason is left as excercise to reader :)
        sort (upper.begin(), upper.end());
        for (int i = 0 ; i<n ; i++)
        {
            points[lower[i].second] += i; // lower bounds of singers which are higer than ith singer
            points[upper[i].second] += i; // upper bounds of singers which are less than ith singer
        }
        for (int i = 0 ; i < n ; i++)
        {
            cout << points[i] << " "; //output the singers in order
        }
        cout << "\n";
    }
}