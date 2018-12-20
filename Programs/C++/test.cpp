#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
	char arr[50], final[50];
	gets(arr);
	int i =0;
	for(int k = 0; k<50; k++)
	{
		if(arr[k] != 'a' && arr[k] != 'e' && arr[k] != 'i' && arr[k] != 'o' && arr[k] != 'u' && arr[k] != 'A' && arr[k] != 'E' && arr[k] != 'I' && arr[k] != 'O' && arr[k] != 'U')
		{
			final[i] = arr[k];
			i++;
		}
	}
	puts(final);
}