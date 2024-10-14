// brute force approach
// using two nested for loop => tc: n^2
// algo: samNotes

// optimal approach
// tc: 2n and sc: n + n (for answer)

#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[i] <= st.top())
        {
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;

        else
            ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}
