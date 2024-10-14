//we can do also without stack with help of vector's property push , back etc.
// stack will increase the step to convert the output stack into vector
//pen and paper
//tc: 2n ans sc:n

#include<bits/stdc++.h>
vector<int> collidingAsteroids(vector<int> &arr)
{
    //    Write your code here.
    stack<int> st;

    for(int i=0;i<arr.size();i++){
        if(arr[i]>0)    st.push(arr[i]);
        else{
            while (! st.empty() && abs(arr[i]) > st.top() && st.top() >0) {
                st.pop();
            }

            if(! st.empty() && abs(arr[i])==st.top()) {
                st.pop();
            }  
            
            else if(st.empty() || st.top() <= 0)    st.push(arr[i]);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());

    return ans;
}


