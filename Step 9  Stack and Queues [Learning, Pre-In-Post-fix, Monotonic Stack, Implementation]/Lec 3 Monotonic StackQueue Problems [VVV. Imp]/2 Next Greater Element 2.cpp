// concept of circular array

// brute force approach
// algo: samNotes
// tc: o(n^2)

// optimal approach
// tc: 4n and sc: 2n+ n(for answer storage)

#include <bits/stdc++.h>
vector<int> nextGreaterElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = 2 * n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[i % n] >= st.top())
        {
            st.pop();
        }

        if (i < n)
        {
            if (st.empty())
                ans[i] = -1;

            else
                ans[i] = st.top();
        }

        st.push(arr[i % n]);
    }

    return ans;
}
