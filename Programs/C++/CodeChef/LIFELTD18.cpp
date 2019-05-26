#include<bits/stdc++.h>
using namespace std;
int main()
{
	 long t;
	 cin>>t;
	 while(t--)
	 {
		char a[3][3];
		for(long i=0;i<3;i++)
		{
		    for(long j=0;j<3;j++)
		    {
		   		cin>>a[i][j];
		    }
		}
		int f=0;
		for(long i=0;i<3;i++)
		{
		    for(long j=0;j<3;j++)
		    {
				  if(a[i][j]=='l'&&i<2&&j<2)
				  {
				      if((a[i+1][j+1]=='l'&&a[i+1][j]=='l'))
				      {
				   			f=1;
				   			break;
				      }
				  }
		    }
		}
		if(f)
		{
		    cout<<"yes"<<endl;
		}
		else
		{
		    cout<<"no"<<endl;
		}
	}

}