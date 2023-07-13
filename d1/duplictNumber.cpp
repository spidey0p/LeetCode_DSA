#include <iostream>
using namespace std;

class solution
{
public:
    int findDuplicate(int nums[])
    {
        int fast = nums[0];
        int slow = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    solution S;
    int arr[] = {1, 2, 3, 4, 5, 5};

    int x = S.findDuplicate(arr);
    cout << x;
    return 0;
}