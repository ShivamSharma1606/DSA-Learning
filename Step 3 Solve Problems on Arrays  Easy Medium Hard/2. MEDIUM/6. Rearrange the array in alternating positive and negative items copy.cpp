// optimal approach
#include <bits/stdc++.h>
vector<int> alternateNumbers(vector<int> &arr)
{

    int pos = 0;
    int neg = 1;
    int n = arr.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {

        if (arr[i] > 0)
        {
            ans[pos] = arr[i];
            pos += 2;
        }   
        else
        {
            ans[neg] = arr[i];
            neg += 2;
        }
    }
    return ans;
}

int main()
{
}