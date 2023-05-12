// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the number of Stairs:";
//     cin >> n;
//     vector<int> dp(n + 1, -1);
//     dp[0] = 1;
//     dp[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     cout << "Number of ways to climbing the Stairs is: " << dp[n] << endl;

//     return 0;
// }

/*Output
Enter the number of Stairs:5
Number of ways to climbing the Stairs is: 8
TC = O(N)
SC = O(N)
*/

// with Space optimization this program can be rewritten as:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of stairs:";
    cin >> n;
    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << "Number of ways to climbing the Stairs is: " << prev;
    return 0;
}
