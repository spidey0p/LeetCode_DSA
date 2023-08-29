#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // number of row
    int m = matrix[0].size(); // number of column
    vector<int> ans;
    int top = 0, btn = n - 1;
    int left = 0, right = m - 1;

    while (top <= btn && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[left][i]);
        }
        top++;

        for (int i = top; i <= btn; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= btn) // when there is asingle line
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[btn][i]);
            }
            btn--;
        }

        if (left <= right) // when there is asingle line
        {
            for (int i = btn; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}