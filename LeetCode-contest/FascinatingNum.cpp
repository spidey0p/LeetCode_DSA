#include <bits/stdc++.h>
using namespace std;
bool isFascinating(int n)
{
    int x = 2 * n;
    int y = 3 * n;
    string str1 = to_string(n);
    string str2 = to_string(x);
    string str3 = to_string(y);
    string str4 = str1 + str2 + str3;

    unordered_set<char> st;
    for (auto it : str4)
        st.insert(it);

    for (int i = 0; i < str4.size(); i++)
    {
        if (st.size() == 9 && str4[i] != '0')
            return true;
        else
            return false;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    cout << isFascinating(n);
}

//
//
// soln

// bool isFascinating(int n)
// {
//     string nStr = to_string(n);
//     string abc = nStr + to_string(2 * n) + to_string(3 * n);
//     if (abc.length() != 9)
//     {
//         return false;
//     }
//     sort(abc.begin(), abc.end());
//     for (int i = 0; i < 9; i++)
//     {
//         if (abc[i] != '1' + i)
//         {
//             return false;
//         }
//     }
//     return true;
// }