// brute force approach
// using two for loop :  tc: n^2 ans sc: 1
// algo : samNotes

// optimal approach
// pen and paper: hard to understand make all subarrays and apply this algo
// tc: 5n and sc: 5n

class Solution
{
public:
    vector<int> nextSmaller(vector<int> arr)
    {
        int n = arr.size();

        vector<int> nse(n, n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            nse[i] = st.empty() ? n : st.top(); //we are entering the index not the value
            st.push(i);
        }
        return nse;
    }

    vector<int> previousSmallerEqual(vector<int> arr)
    {
        int n = arr.size();
        vector<int> psse(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] < arr[st.top()]) //< is use because we their are same two value then we have to return that value which is come first
                st.pop();                         // the main line difference
            psse[i] = st.empty() ? -1 : st.top(); // differnce
            st.push(i);
        }
        return psse;
    }

    int sumSubarrayMins(vector<int> &arr)
    {

        vector<int> nse = nextSmaller(arr);
        vector<int> pse = previousSmallerEqual(arr);
        int total = 0;
        int mod = int(1e9 + 7);
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
        }

        return total;
    }
};
