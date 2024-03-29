// #include <bits/stdc++.h>
// using namespace std;

// bool subSet(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return true;

//     if (ind == 0)
//         return arr[0] == target;

//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     bool notTaken = subSet(ind - 1, target, arr, dp);

//     bool taken = false;
//     if (arr[ind] <= target)
//         taken = subSet(ind - 1, target - arr[ind], arr, dp);

//     return dp[ind][target] = notTaken || taken;
// }
// bool subSetSum(int n, int k, vector<int> &arr)
// {

//     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return subSet(n - 1, k, arr, dp);
// }
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4};
//     int k = 4;
//     int n = arr.size();

//     if (subSetSum(n, k, arr))
//     {
//         cout << "Subset with given target found";
//     }
//     else
//         cout << "Subset with given target not fount";
// }/

#include <bits/stdc++.h>
using namespace std;

bool subSet(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[ind - 1][target];

            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTake || take;
        }
    }
    return dp[n - 1][k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    int k = 4;
    int n = arr.size();

    if (subSet(n, k, arr))
        cout << "Target found!" << endl;
    else
        cout << "Target not found!" << endl;
}