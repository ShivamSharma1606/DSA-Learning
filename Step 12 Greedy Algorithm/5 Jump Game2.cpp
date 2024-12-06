// brute force approach using recursion [chatGPT solution]
// tc: o(n^n) and sc: o(1)
#include <iostream>
#include <vector>
#include <climits>

int minJumpsHelper(const std::vector<int> &nums, int position, std::vector<int> &memo)
{
    // If we are at or beyond the last index, no further jumps are needed
    if (position >= nums.size() - 1)
    {
        return 0;
    }

    // If this position is already computed, return its result
    if (memo[position] != -1)
    {
        return memo[position];
    }

    // If we can't move further from this position
    if (nums[position] == 0)
    {
        return INT_MAX; // Unreachable, so return a large number
    }

    int min_jumps = INT_MAX;

    // Explore all possible jumps from this position
    for (int step = 1; step <= nums[position]; ++step)
    {
        int next_position = position + step;
        int jumps = minJumpsHelper(nums, next_position, memo);

        // Only consider valid paths (jumps != INT_MAX)
        if (jumps != INT_MAX)
        {
            min_jumps = std::min(min_jumps, jumps + 1);
        }
    }

    // Memoize the result for this position
    memo[position] = min_jumps;
    return min_jumps;
}

int jump(const std::vector<int> &nums)
{
    // Memoization vector initialized with -1 (uncomputed)
    std::vector<int> memo(nums.size(), -1);
    int result = minJumpsHelper(nums, 0, memo);
    return (result == INT_MAX) ? -1 : result; // If unreachable, return -1
}

int main()
{
    std::vector<int> nums = {2, 3, 1, 1, 4};
    int result = jump(nums);
    if (result != -1)
    {
        std::cout << "Minimum jumps needed: " << result << std::endl;
    }
    else
    {
        std::cout << "Cannot reach the last index." << std::endl;
    }
    return 0;
}

// better approach : dp

// optimal approach : TC: o(n)[find with help of testcase] and sc:1

int minJumps(vector<int> &arr, int n)
{
    int jump = 0;
    int l = 0;
    int r = 0;
    int farthest = 0;

    while (r < n - 1)
    {
        for (int index = l; index <= r; index++)
        {
            farthest = max(farthest, arr[index] + index);
        }

        // to check can we reach to the solution or not
        if (farthest <= r)
            return -1;
        l = r + 1;
        r = farthest;
        jump++;
    }
    return jump;
}