// see the submission history for more reference[codestudio]
// by this method we can only return length


//ultra pro max optimal solution using binary search 
// tc:O(n*logn) and sc: o(n)
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    if (n == 0)
        return 0;
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;

    for (int i = 1; i < n; i++)
    {

        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}
