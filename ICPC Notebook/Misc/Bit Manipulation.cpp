n = n << i;           // Multiply n with 2^i
n = n >> 1;           // Divide n by 2^i
int computeXOR(int n) //compute xor from 1...n
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
bool poweroftwo(int x) //check if x is power of two
{
    return x & (x - 1) == 0;
}
ch |= " ";           //Upper to Lower
ch &= "_";           //Lower to Upper
int logarithm(int x) //find log2
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}
//below all are 0 indexed
if (x & (1 << i))
{
    //ith bit is set
}
x |= (1 < < k)         //sets the kth bit of x to one
x &= ~(1 << k)     //unsets the kth bit of x to zero
x ^= (1 << k) //Inverts the kth bit of x
T = (S & (-S))     //T is a power of two with only one bit set which is the LSB.
~(x & 0)           //set all bits
S = (1 << n) - 1   //set all bits is s till n

// This function will return n % d.
// d must be one of: 1, 2, 4, 8, 16, 32, ...
unsigned int getModulo(unsigned int n, unsigned int d)
{
    return (n & (d - 1));
}
// __builtin_clz(x): the number of zeros at the beginning of the number
// __builtin_ctz(x) : the number of zeros at the end of the number
// __builtin_popcount(x) : the number of ones in the number
// __builtin_parity(x) : the parity(even or odd) of the number of ones
