int sumLessThanEquaTo(vector<int> &nums, int goal)
{

    int n = nums.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int len = 0;

    while (r < n)
    {
        sum += (nums[r] % 2);

        while (sum > goal)
        {
            sum = sum - (nums[l] % 2);
            l++;
        }

        if (sum <= goal)
        {
            len += (r - l + 1);
        }
        r++;
    }
    return len;
}

int numberOfSubarrays(vector<int> &nums, int goal)
{

    int first = sumLessThanEquaTo(nums, goal);
    int second = sumLessThanEquaTo(nums, goal - 1);

    return (first - second);
}