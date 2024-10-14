//pen and paper: make matrix for each loop
//prefix sum concept
//tc:   O(m*n)  + O(n*2*m) and sc: O(m*n)  +O(n)

#include<bits/stdc++.h>
vector<vector<int>> prefixSumArray(vector<vector<int>> &mat, int n, int m) {

  
  vector<vector<int>> ans(n,vector<int>(m));

  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += mat[i][j];
      if (mat[i][j] == 0) {
        sum = 0;
      }
      ans[i][j] = sum;
    }
  }

  return ans;
}

int largestRectangleArea(vector<int> &arr) {
  stack<int> st;
  int maxi = 0;
  int n = arr.size();

  for (int i = 0; i < arr.size(); i++) {

    while (!st.empty() && arr[st.top()] > arr[i]) {
      int element = st.top();
      st.pop();
      int nse = i;
      int pse = st.empty() ? -1 : st.top();
      maxi = max(maxi, (nse - pse - 1) * arr[element]);
    }
    st.push(i);
  }
  while (!st.empty()) {
    int element = st.top();
    st.pop();
    int nse = n;
    int pse = st.empty() ? -1 : st.top();
    maxi = max(maxi, (nse - pse - 1) * arr[element]);
  }

  return maxi;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
  // Write your code here.

  vector<vector<int>> ans = prefixSumArray(mat, n, m);

  int maxArea=0;

  for (int i = 0; i < n; i++) {
    maxArea = max(maxArea,largestRectangleArea(ans[i]) );
  }
  return maxArea;
}       