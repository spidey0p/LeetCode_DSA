#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    int n = s.length();
    int lb = 0;
    int rb = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            lb++;
        if (s[i] == ')')
            rb++;
    }
    return abs(lb - rb);
}