#include <bits/stdc++.h>
using namespace std;

int semiOrderedPermutation(vector<int> &nums)
{
    int n = nums.size();

    int min = 0, max = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            min = i;
        if (nums[i] == n)
            max = i;
    }
    if (min < max)
        return (min + n - max - 1);

    return (min + n - max - 1) - 1;
}
int main()
{
}