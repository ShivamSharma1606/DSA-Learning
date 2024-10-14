
#include <bits/stdc++.h>
using namespace std;

// Function to return the count of number of elements in union of two arrays.
int doUnion(int a[], int n, int b[], int m)
{
    // code here
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(b[i]);
    }
    int arr[st.size()] = {0};
    int i = 0;
    for (auto it : st)
    {
        arr[i++] = it;
    }

    return st.size();
}
