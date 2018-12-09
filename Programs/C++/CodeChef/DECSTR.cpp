#include <iostream>

#include<bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--)
   {  stack<char>s;
      int k;cin>>k;
      char z[105]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
      int c=0;
      if(k<=25)
      for(int i=0;i<=k;i++)
      s.push(z[i]);
      else if(k<=50)
      { int i=0;
         for( i=0;i<=k;i++)
      s.push(z[i]);
      for(int j=i;j<=k+1;j++)
      s.push(z[j]);

      }
      else if(k<=75)
      { int i;
         for( i=0;i<52;i++)
      s.push(z[i]);
      for(int j=i;j<=k+2;j++)
      s.push(z[j]);


      }
      else if(k<=100)
      {
         int i;
          for( i=0;i<78;i++)
      s.push(z[i]);
      for(int j=i;j<=k+3;j++)
      s.push(z[j]);
      }


      while(!s.empty())
      {
         cout<<s.top();s.pop();
      }
      cout<<endl;
   }
	// your code goes here
	return 0;
}
