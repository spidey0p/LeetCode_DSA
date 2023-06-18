#include <bits/stdc++.h>
using namespace std;

int distanceTraveled(int mainTank, int additionalTank)
{

    int i = 1, ans = 0;
    while (i <= mainTank)
    {

        ans += 10;

        if (i % 5 == 0 && additionalTank > 0)
        {
            mainTank++;
            additionalTank--;
        }

        i++;
    }

    return ans;
}
