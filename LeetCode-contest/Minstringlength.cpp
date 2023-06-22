#include <bits/stdc++.h>
using namespace std;

int minLength(string s)
{
    stack<char> stk;

    for (char ch : s)
    {
        if (!stk.empty() && (stk.top() == 'A' && ch == 'B' || stk.top() == 'C' && ch == 'D'))
        {
            stk.pop();
        }
        else
        {
            stk.push(ch);
        }
    }
    return stk.size();
}

int main()
{
    string s;

    cout << "Enter the string:";

    cin >> s;

    int length = minLength(s);

    cout << "Min Length is: " << length << endl;
}
