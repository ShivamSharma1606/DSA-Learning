// brute force approach using two for loop
// notes: samNote
//tc:n^2 and sc: 1


//optimal approch
//very very hard question
// tc: 10n and sc:10n

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &arr)
    {
        // Write your code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,n);

        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && arr[i] >= arr[st.top()])
            {
                st.pop();
            }

            if (st.empty())
                ans[i] = n;

            else
                ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> previousGreaterElement(vector<int> &arr)
    {
        // Write your code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,-1);

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && arr[i] > arr[st.top()])
            {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;

            else
                ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
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

    long long sumSubarrayMins(vector<int> &arr)
    {

        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = previousSmallerElement(arr);
        long long total = 0;
        // int mod = int(1e9 + 7);
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += right * left * 1LL * arr[i];
        }

        return total;
    }

    long long sumSubarrayMax(vector<int> &arr)
    {

        vector<int> nse = nextGreaterElement(arr);
        vector<int> pse = previousGreaterElement(arr);
        long long total = 0;
        // int mod = int(1e9 + 7);
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += right * left * 1LL * arr[i];
        }

        return total;
    }

    long long subArrayRanges(vector<int> &nums)
    {

        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};

