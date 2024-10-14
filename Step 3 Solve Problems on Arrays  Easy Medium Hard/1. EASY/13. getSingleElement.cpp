#include <vector>

// my approach only work if array is sorted
int getSingleElement(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i = i + 2)
    {
        if (arr[i] != arr[i + 1])
        {
            return arr[i];
        }
    }
}

// optimal striver approach
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xxor = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xxor = xxor ^ nums[i];
        }

        return xxor;
    }
};

int main()
{
}