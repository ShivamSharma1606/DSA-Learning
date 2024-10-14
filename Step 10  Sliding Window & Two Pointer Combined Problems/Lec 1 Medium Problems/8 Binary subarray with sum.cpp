// pseudo code is explain in samNotes

/*
STEPS TO REACH THE SOLUTION
1. First we find all the subarray whose sum is equal to or less than goal
2. Second we find all the subarray whose sum is equal to goal-1 or less then goal-1
3. subtract the step 2 - step 1 -> we get all the subarray whose sum is equal to goal
*/

// optimal solution : O(2n)

int sumLessThanEquaTo(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int n = nums.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int len = 0;

    while (r < n)
    {
        sum += nums[r];

        while (sum > goal)
        {
            sum = sum - nums[l];
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

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    /*when this type of question is given
    where specific goal is defined i.e ==
    then we first find the number of subarray which are lesser than k
    second subarray lesser than k-1
    and subtract first-second
    this method is used in upcoming question where specific value of k has to be specified
    */
    if (goal < 0)
        return 0; // useful if goal is less than 0 because we cannot calulate goal-1
    int first = sumLessThanEquaTo(nums, goal);
    int second = sumLessThanEquaTo(nums, goal - 1);

    return (first - second);
}
