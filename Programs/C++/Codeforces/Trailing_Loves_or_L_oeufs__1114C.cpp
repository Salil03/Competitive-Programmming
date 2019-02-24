#include<bits/stdc++.h>
using namespace std;

unsigned long long int Zeroes(unsigned long long int base, unsigned long long int number)
{
  unsigned long long int z = 0;
  for (unsigned long long int f = 1; number >= 1; f %= (int)std::pow(base, std::ceil(std::log(number) / std::log(base)) + 1), f *= number--)
    while (f % base == 0)
    {
      f /= base;
      z++;
    }
  return z;
}
int main()
{
   unsigned long long int n,b;
   cin >> n >> b;
   cout << Zeroes(b,n);
   return 0;
}