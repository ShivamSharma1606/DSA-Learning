//brute force approach : o(n^2)
//samnotes

//optimal approach
//tc: 2xO(2n) and sc: O(n)

int sumLessThanEquaTo(vector<int> &nums, int goal)
{

    int n = nums.size();
    int l = 0;
    int r = 0;
    map<int,int> mpp;
    int len = 0;

    while (r < n)
    {
        mpp[nums[r]]++;

        while (mpp.size() > goal)
        {
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
        }

        if (mpp.size() <= goal)
        {
            len += (r - l + 1);
        }
        r++;
    }
    return len;
}
int kDistinctSubarrays(vector<int> &nums, int n, int goal)
{
    // Write your code here
    int first = sumLessThanEquaTo(nums, goal);
    int second = sumLessThanEquaTo(nums, goal - 1);

    return (first - second);
}