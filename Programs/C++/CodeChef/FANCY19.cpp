#include<bits/stdc++.h>
using namespace std;
int removeDupWord(string str)
{
   string word = "";
   for (auto x : str)
   {
       if (x == ' ')
       {
       		if(word == "not")
       		{
       			cout << "Real Fancy\n";
       			return 1;
       		}
       		word  = "";
       }
       else
       {
           word = word + x;
       }
   }
   cout << "regularly fancy\n";
   return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	cin.ignore();
	while(t--)
	{
		string s;
		getline(cin, s);
		if(s == "not")
		{
			cout << "Real Fancy\n";
		}
		else
		{
			removeDupWord(s);
		}
	}
}