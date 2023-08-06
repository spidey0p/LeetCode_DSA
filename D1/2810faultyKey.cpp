#include <bits/stdc++.h>
using namespace std;

string finalString(string s)
{
    int n = s.size();
    string ans = "";
    for (auto &it : s)
    {
        if (it == 'i')
        {
            reverse(ans.begin(), ans.end());
        }
        else
            ans += it;
    }
    return ans;
}