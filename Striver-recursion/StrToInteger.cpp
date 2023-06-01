#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    long reg = 0;
    int flag = 1;
    for (int i = 0; i < s.size();)
    {
        i = s.find_first_not_of(' ');
        if (s[i] == '-' || s[i] == '+')
            flag = (s[i++] == '-') ? -1 : 1;
        while ('0' <= s[i] && s[i] <= '9')
        {
            reg = reg * 10 + (s[i++] - '0');
            if (reg * flag >= INT_MAX)
                return INT_MAX;
            if (reg * flag <= INT_MIN)
                return INT_MIN;
        }
        return reg * flag;
    }
}
int main()
{
    string s;
    cout << "Enter the string:";
    cin >> s;
    int ans = myAtoi(s);
    cout << ans << endl;
}