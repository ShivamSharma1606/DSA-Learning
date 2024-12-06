// tc: O(n) and sc: O(1)

bool canJump(vector<int> &nums)
{
    int maxIndex = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (maxIndex < i) // if come to that element where we cannot come[by finding maxIndex] so return 0
            return false;
        maxIndex = max(maxIndex, i + nums[i]); // finding how much we can go further
    }
    return true;
}