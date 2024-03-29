// Stock Buy or Sell to get max profite

#include <bits/stdc++.h>
using namespace std;

int maxProfite(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minPrice = (min(minPrice, arr[i]));
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    return maxPro;
}
int main()
{
    vector<int> arr = {7, 1, 5, 3, 9, 4};
    int maxPro = maxProfite(arr);
    cout << "Max Profit is :" << maxPro << endl;
}