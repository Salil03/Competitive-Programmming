#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t, i;
    char map[27], s[101];

    cin >> t >> map;

    while (t--) {
        cin >> s;

        for (i = 0; s[i]; i++) {
            if      (islower(s[i]))  s[i] = map[s[i] - 'a'];
            else if (isupper(s[i]))  s[i] = toupper(map[s[i] - 'A']);
            else if (s[i] == '_')    s[i] = ' ';
        }

        cout << s << "\n";
    }

    return 0;
}
