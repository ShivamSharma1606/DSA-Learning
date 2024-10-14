// brute force approach
// samNotes

// test case: 3 3 3 1 2 1 1 2 3 3 4

// better approach : tc-> o(2n) sc->o(s)

int findMaxFruits(vector<int> &arr, int n)
{
    // Write your code here.
    int k = 2; // we can convert this code int general basket code
    int l = 0;
    int r = 0;
    map<int, int> mpp;
    int len = 0;
    int maxi = 0;

    while (r < n)
    {

        mpp[arr[r]]++;
        if (mpp.size() > k)
        {

            while (mpp.size() > k)
            {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        if (mpp.size() <= k)
        {
            len = r - l + 1;
            maxi = max(maxi, len);
        }
        r++;
    }
    return maxi;
}

// optimal approach     : o(n)

class Solution
{
public:
    int totalFruits(vector<int> &arr)
    {

        int k = 2; // we can convert this code int general basket code
        int l = 0;
        int r = 0;
        map<int, int> mpp;
        int len = 0;
        int maxi = 0;

        while (r < arr.size())
        {

            mpp[arr[r]]++;
            if (mpp.size() > k)
            {

                if (mpp.size() > k)
                {
                    mpp[arr[l]]--;
                    if (mpp[arr[l]] == 0)
                    {
                        mpp.erase(arr[l]);
                    }
                    l++;
                }
            }
            if (mpp.size() <= k)
            {
                len = r - l + 1;
                maxi = max(maxi, len);
            }
            r++;
        }
        return maxi;
    }
};
