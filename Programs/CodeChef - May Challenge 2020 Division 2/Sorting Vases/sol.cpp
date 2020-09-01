#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int pots[n+1];
        vector<int> ds(n+1,-1);
        for(int i=1;i<=n;i++) cin>>pots[i];
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            if(ds[x]==-1 && ds[y]==-1) ds[x]=ds[y]=x;
            else if(ds[x]==-1) ds[x]=ds[y];
            else if(ds[y]==-1) ds[y]=ds[x];
            else
            {
                int tmp=ds[y];
                for(int j=1;j<=n;j++) if(ds[j]==tmp) ds[j]=ds[x];
            }
        }
        for(int i=1;i<=n;i++) if(ds[i]==-1) ds[i]=0;
        int ans=0;
        for(int i=1;i<=n;i++) 
        {
            if(pots[i]!=i && ds[pots[i]]==0)
            {
                ans++;
                swap(pots[i],pots[pots[i]]);
                --i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(ds[pots[i]]==ds[i] && pots[i]!=i) 
            {
                swap(pots[i],pots[pots[i]]);
                --i;
            } 
        }
        for(int i=1;i<=n;i++)
        {
            if(ds[i]!= ds[pots[i]])
            {
                for(int j=1;j<=n;j++)
                {
                    if(ds[j]==ds[pots[i]] && ds[pots[j]]==ds[i])
                    {
                        swap(pots[i],pots[j]);
                        if(pots[j]!=j) swap(pots[j],pots[pots[j]]);
                        ++ans;
                        break;
                    }
                }
            }
            if(ds[i]==ds[pots[i]] && pots[i]!= i)
            {
                swap(pots[i],pots[pots[i]]);
                --i;
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(ds[i]!=ds[pots[i]])
            {
                swap(pots[i],pots[pots[i]]);
                ++ans;--i;
            }
            else if(ds[i]==ds[pots[i]] && pots[i]!=i)
            {
                swap(pots[i],pots[pots[i]]);
                --i;
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     if(pots[i]!=i)
        //     {
        //         if(ds[i]==0)
        //         {
        //             swap(pots[i],pots[pots[i]]);++ans;--i;
        //         }
        //         if(ds[pots[i]]!=ds[i])
        //         {
        //             swap(pots[i],pots[pots[i]]);++ans;--i;
        //         }
        //         else if(ds[pots[i]]==ds[i])
        //         {
        //             swap(pots[i],pots[pots[i]]);--i;
        //         }
        //     }

        // }
        cout<<ans<<endl;
    }
}