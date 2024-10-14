
void printVector(const vector<int> &vector)
{
    for (int num : vector)
    {
        cout << num;
    }
}
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();

    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        printVector(nums);
    for (int i = j + 1; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    printVector(nums);
}

int main()
{
}