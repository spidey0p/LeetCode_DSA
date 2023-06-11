#include <bits/stdc++.h>
using namespace std;

int findNonMinOrMax(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return -1;

    int minNum = INT_MAX;
    int maxNum = INT_MIN;

    for (int num : nums)
    {
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }

    for (int num : nums)
    {
        if (num != minNum && num != maxNum)
        {
            return num;
        }
    }
    return -1;
}