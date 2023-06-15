#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> rng;

    for (int i = 0; i < nums.size(); i++)
    {
        int start = nums[i];

        while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
        {
            i++;
        }
        if (start != nums[i])
        {
            rng.push_back(to_string(start) + "->" + to_string(nums[i]));
        }
        else
        {
            rng.push_back(to_string(start));
        }
    }
    return rng;
}