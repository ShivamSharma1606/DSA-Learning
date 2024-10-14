// brute force approach : tc->o(n^2)
// samNotes

// better approach : o(2n)
#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<char, int> mpp;

    while (r < str.size())
    {
        mpp[str[r]]++;

        while (k < mpp.size())
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
            {
                mpp.erase(str[l]);
            }
            l++;
        }
        if (k >= mpp.size())
        { // this if statement is redudant in better solution it is for optimal solution
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

// optimal approach : o(n)

#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<char, int> mpp;

    while (r < str.size())
    {
        mpp[str[r]]++;

        if (k < mpp.size())
        {
            mpp[str[l]]--;

            if (mpp[str[l]] == 0)
            { // the only difference between optimal and better solution is that (if is replaced by which{ it itself have o(n) complexity})
                mpp.erase(str[l]);
            }
            l++;
        }
        if (k >= mpp.size())
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
