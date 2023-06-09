#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    char answer = letters[0];
    for (int i = 0; i < letters.size(); i++)
    {
        if (letters[i] > target)
        {
            answer = letters[i];
            break;
        }
    }
    return answer;
}

int main()
{
    vector<char> letters = {{'c'}, {'f'}, {'j'}};
    char target = 'c';
    cout << nextGreatestLetter(letters, target);
}