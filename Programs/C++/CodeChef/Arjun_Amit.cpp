#include <bits/stdc++.h>

using namespace std;
bool checkPrime(int n);

int main()
{
    while (true)
    {
        register int number;
        cin >> number;
        register int counter = 0;
        register int numbers = 0;
        time_t start = clock();
        while (counter < number)
        {
            numbers++;
            if (checkPrime(numbers))
                counter++;
        }
        double time_diff = (clock() - start);
        cout << numbers << endl;
        cout << "Time needed to process in ms: " << time_diff << endl;
    }
}

vector<int> primes;
bool checkPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 0; i < primes.size(), primes.at(i) <= sqrt(n); i++)
    {

        if (n % primes.at(i) == 0)
            return false;
    }
    primes.push_back(n);
    return true;
}