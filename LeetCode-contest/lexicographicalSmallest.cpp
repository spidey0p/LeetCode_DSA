#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string makePalindrome(string s)
{
    int n = s.length();
    string result = s;

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            char minChar = min(s[i], s[n - i - 1]);
            result[i] = minChar;
            result[n - i - 1] = minChar;
        }
    }

    return result;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    string palindrome = makePalindrome(s);

    cout << "Resulting palindrome: " << palindrome << endl;

    return 0;
}
