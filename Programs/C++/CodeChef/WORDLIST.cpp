#include <bits/stdc++.h>
using namespace std;
typedef long long lng;

char line[83];
set < string > cs;

int main()
{
   int n;
   scanf("%d", &n);
   cs.clear();
   getchar();
   while(n--)
   {
       gets(line);
       int len = strlen(line);
       for(int i = 0; i < len; ++i)
       {
           line[i] = tolower(line[i]);
           if(line[i] < 'a' || line[i] > 'z')
               line[i] = ' ';
       }
       stringstream ss(line);
       string word;
       while(ss >> word)
           cs.insert(word);
   }
   printf("%d\n", (int)cs.size());
   for(set < string > :: iterator it = cs.begin(); it != cs.end(); it++)
       puts((*it).c_str());
   return 0;
}