// Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = INT_MIN;
        for (auto it : nums)
        {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main()
{
    solution S;
    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    int max = S.maxSubArray(nums);
    cout << "The max sum is:" << max;
}