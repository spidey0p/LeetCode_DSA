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
        else if (lb > 0)
            lb--;
        else
            rb++;
    }
    return abs(lb + rb);
}
int main()
{
    string str;
    cout << "Enter the string:";
    cin >> str;
    int x = minAddToMakeValid(str);
    cout << x << endl;
}