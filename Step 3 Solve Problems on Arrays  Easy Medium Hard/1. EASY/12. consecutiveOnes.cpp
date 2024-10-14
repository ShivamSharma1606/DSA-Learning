// brute force approach
int consecutiveOnes(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();

    int i = 0;
    vector<int> max;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            i++;
        }
        else
        {
            int sum = 0;
            for (i; i < n; i++)
            {
                if (arr[i] == 1)
                {
                    sum = sum + arr[i];
                }
                else
                {
                    break;
                }
            }
            max.push_back(sum);
        }
    }
    return *max_element(max.begin(), max.end());
}

int main()
{
}

// optimial approach

int consecutiveOnes(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();

    int i = 0;
    vector<int> max;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            i++;
        }
        else
        {
            int sum = 0;
            for (i; i < n; i++)
            {
                if (arr[i] == 1)
                {
                    sum = sum + arr[i];
                }
                else
                {
                    break;
                }
            }
            max.push_back(sum);
        }
    }
    return *max_element(max.begin(), max.end());
}