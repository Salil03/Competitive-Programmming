/*
 * Outputs random number between 1 and 10^6, inclusive.
 * To generate different values, call "igen.exe" with different parameters.
 * For example, "igen.exe 1" returns 504077, but "igen.exe 3" returns 808747.
 * 
 * It is typical behaviour of testlib generator to setup randseed by command line.
 */

#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    long long int n = (long long int)1e6, k = 100;
    cout << n << " " << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << rnd.next(1LL, 140LL) << endl;
    }
    return 0;
}