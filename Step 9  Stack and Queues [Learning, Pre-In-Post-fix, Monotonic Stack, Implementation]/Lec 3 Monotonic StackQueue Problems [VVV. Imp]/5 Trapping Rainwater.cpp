/*
Brute force approach
Concepts: prefixMax(leftMax) && SuffixMax(rightMax)
tc: 3n
sc: 2n
*/

long long getTrappedWater(long long *arr, int n)
{
    // Write your code here.

    long long rightMax[n];
    long long leftMax[n];
    leftMax[0] = arr[0];
    rightMax[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    long long total = 0;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] < leftMax[i] && arr[i] < rightMax[i])
        {
            total += min(leftMax[i], rightMax[i]) - arr[i];
        }
    }

    return total;
}

// optimal approach
// tc: o(n) and sc: 1
class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int leftmax = 0, rightmax = 0, total = 0;
        int l = 0;
        int r = arr.size() - 1;

        while (l < r)
        {
            if (arr[l] <= arr[r])
            {
                if (arr[l] < leftmax)
                    total += leftmax - arr[l];
                else
                    leftmax = arr[l];
                l++;
            }
            else
            {
                if (arr[r] < rightmax)
                    total += rightmax - arr[r];
                else
                    rightmax = arr[r];
                r--;
            }
        }
        return total;
    }
};