#include <iostream>
#include <string>

using namespace std;

int getPunishmentNumber(int n)
{
    int punishment = 0;

    for (int i = 1; i <= n; i++)
    {
        int square = i * i;
        string squareStr = to_string(square);
        int sum = 0;

        // Check if the decimal representation of square satisfies the condition
        for (int j = 0; j < squareStr.length(); j++)
        {
            int digit = squareStr[j] - '0';
            sum += digit;

            // If the sum equals i, add the square to the punishment number
            if (sum == i)
            {
                punishment += square;
                break;
            }
        }
    }

    return punishment;
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int punishmentNumber = getPunishmentNumber(n);

    cout << "Punishment number of " << n << ": " << punishmentNumber << endl;

    return 0;
}
