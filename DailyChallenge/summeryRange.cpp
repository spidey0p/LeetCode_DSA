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

int main()
{
    // Test case 1
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> result1 = summaryRanges(nums1);

    cout << "Result 1: ";
    for (const auto &range : result1)
    {
        cout << range << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {1, 3, 4, 6, 8, 9};
    vector<string> result2 = summaryRanges(nums2);

    cout << "Result 2: ";

    for (const auto &range : result2)
    {
        cout << range << " ";
    }
    cout << endl;

    return 0;
}