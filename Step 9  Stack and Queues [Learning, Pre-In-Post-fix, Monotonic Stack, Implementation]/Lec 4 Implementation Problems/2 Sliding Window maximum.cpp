//brute force alog using two for loops
// algo : samNotes
//tc: o(n-k)*k and sc:  n-k

//optimal approach
//concept: monotonic stack and doubly dequeue(push and pop from both end i.e we can push element at front and end & pop element at front and end )
//tc: 2n and    o(k)    
//pen and paper

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque <int> dq;
    vector<int> ans;

    int n=nums.size();
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front() == i-k )    dq.pop_front();

        while(!dq.empty() && nums[dq.back()]<=nums[i])   dq.pop_back();

        dq.push_back(i);

        if(i>=k-1)  ans.push_back(nums[dq.front()]);
    }

    return ans;
}   