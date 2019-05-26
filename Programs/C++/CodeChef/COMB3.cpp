#include <bits/stdc++.h>
using namespace std;

#define int long long

struct player
{
    int index, rating;
};

bool comp(player p1, player p2)
{
    if(p1.rating == p2.rating)
        return p1.index > p2.index;
    else
        return p1.rating > p2.rating;
}

signed main()
{
    int N, K;
    cin>>N>>K;

    vector<int> friends(N , 0);

    player arr[N];

    for(int i=0 ; i<N ; i++)
    {
        cin>>arr[i].rating;

        arr[i].index = i;
    }

    int ans[N];

    for(int i=0 ; i<K ; i++)
    {
        int x, y;
        cin>>x>>y;

        if(x>y)
            swap(x,y);

        if(arr[x-1].rating > arr[y-1].rating)
            friends[x-1]++;
        else if (arr[x-1].rating < arr[y-1].rating)
            friends[y-1]++;
    }

    sort(arr,arr+N,comp);

    for(int i=0 ; i<N ; i++)
    {
    	int same = -1;
    	int j = i;
    	while(arr[j].rating == arr[i].rating && j <N)
    	{
    		same++;
    		j++;
    	}
        ans[arr[i].index] = N-i-1-friends[arr[i].index] - same;
    }

    for(int i=0 ; i<N ; i++)
    {
        cout<<ans[i]<<" ";
    }
}