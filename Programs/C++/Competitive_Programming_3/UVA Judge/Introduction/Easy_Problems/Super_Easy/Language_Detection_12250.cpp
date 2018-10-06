#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string name = "";
	int number = 0;
	while(cin >> name)
	{
		number++;
		if(name == "#")
		{
			break;
		}
		else if(name == "HELLO")
		{
			cout << "Case " << number << ": " << "ENGLISH\n";
		}
		else if(name == "HOLA")
		{
			cout << "Case " << number << ": " << "SPANISH\n";
		}
		else if(name == "HALLO")
		{
			cout << "Case " << number << ": " << "GERMAN\n";
		}
		else if(name == "BONJOUR")
		{
			cout << "Case " << number << ": " << "FRENCH\n";
		}
		else if(name == "CIAO")
		{
			cout << "Case " << number << ": " << "ITALIAN\n";
		}
		else if(name == "ZDRAVSTVUJTE")
		{
			cout << "Case " << number << ": " << "RUSSIAN\n";
		}
		else
		{
			cout << "Case " << number << ": " << "UNKNOWN\n";
		}
	}
	return 0;
}
