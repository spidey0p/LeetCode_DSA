#include <iostream>
using namespace std;

int reverseBits(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev <<= 1; // rev = rev << 1;

        if (n & 1 == 1)
            rev ^= 1;
        n >>= 1;
    }

    return rev;
}

int main()
{
    unsigned int n = 6;
    cout << reverseBits(n);
    return 0;
}