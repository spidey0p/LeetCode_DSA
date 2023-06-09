#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    // char answer = letters[0];
    // for (int i = 0; i < letters.size(); i++)
    // {
    //     if (letters[i] > target)
    //     {
    //         answer = letters[i];
    //         break;
    //     }
    // }
    // return answer;

    // by Binary search

    int low = 0;
    int high = letters.size() - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (letters[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (letters[low] > target)
    {
        return letters[low];
    }
    return letters[0];
}

int main()
{
    vector<char> letters = {{'c'}, {'f'}, {'j'}};
    char target = 'c';
    cout << nextGreatestLetter(letters, target);
}