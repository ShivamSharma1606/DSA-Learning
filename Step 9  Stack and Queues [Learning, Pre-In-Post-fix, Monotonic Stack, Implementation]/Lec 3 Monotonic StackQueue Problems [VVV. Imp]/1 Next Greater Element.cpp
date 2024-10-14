// monotonic mean which follow some order

// brute force approach(o(n^2))
// algo: sam notes

// optimal approach
// tc: 2n(pen and paper)

#include <bits/stdc++.h>
vector<int> nextGreaterElement(vector<int> &arr, int n)
{
	// Write your code here
	stack<int> st;
	vector<int> ans(n);

	for (int i = n - 1; i >= 0; i--)
	{

		while (!st.empty() && arr[i] >= st.top())
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

int main(){

	nextGreaterElement({5,2,4,7,1,0},6);
	return 0;

}