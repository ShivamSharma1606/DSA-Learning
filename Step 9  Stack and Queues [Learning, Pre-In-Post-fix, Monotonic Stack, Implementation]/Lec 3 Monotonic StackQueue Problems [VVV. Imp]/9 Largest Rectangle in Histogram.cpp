// brute force approach
// tc: 5n and sc: 4n

#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> arr)
{
    int n = arr.size();

    vector<int> nse(n, n);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> previousSmallerElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> psse(n, -1);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
            st.pop();
        psse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psse;
}

int largestRectangle(vector<int> &arr)
{
    // Write your code here.
    vector<int> nse = nextSmallerElement(arr);
    vector<int> pse = previousSmallerElement(arr);
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int area = (nse[i] - pse[i] - 1) * arr[i];
        maxi = max(maxi, area);
    }
    return maxi;
}

// optimal approach
// tc: 2n and sc: n
// without using precomputation

class Solution
{
public:
    int largestRectangleArea(vector<int> &arr)
    {
        stack<int> st;
        int maxi = 0;
        int n = arr.size();

        for (int i = 0; i < arr.size(); i++)
        {

            while (!st.empty() && arr[st.top()] > arr[i])
            {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top(); // gi
                maxi = max(maxi, (nse - pse - 1) * arr[element]);
            }
            st.push(i);
        }
        
        while (!st.empty())
        {
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, (nse - pse - 1) * arr[element]);
        }

        return maxi;
    }
};
