class Solution
{
public:
    int HouseRobber1(vector<int> arr)
    {

        int prev = arr[0];
        int prev2 = 0;

        for (int i = 1; i < arr.size(); i++)
        {

            int take = arr[i];
            if (i > 1)
                take = arr[i] + prev2;
            int notTake = 0 + prev;

            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        vector<int> temp1; // containg all element of nums except nums[0]
        vector<int> temp2; // contiang all element of nums except nums[n-1]
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        return max(HouseRobber1(temp1), HouseRobber1(temp2));
    }
};