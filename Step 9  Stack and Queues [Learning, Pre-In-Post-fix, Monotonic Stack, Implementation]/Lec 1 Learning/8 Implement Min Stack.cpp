#include<bits/stdc++.h>
//tc: o(1) and sc: o(2n)
//brute force approach

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		
		// Constructor
		stack <pair<int,int>> st;
		minStack() 
		{ 
	
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty()){
				st.push({num,num});
			}else{
				st.push({num,min(num,st.top().second)});
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty())	return -1;
			int el=st.top().first;
			st.pop();
			return el;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty())	return -1;
			return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty())	return -1;
			return st.top().second;
		}
};

//optimal approach
//pen and paper: push(12) push(15) push(10) getMin() pop() getMin() top() push(10) top()
//algo: samNotes
//tc: o(1) and sc: o(1)


/*
Your code for the MinStack implementation appears mostly correct.
 However, it seems that there is a potential issue with handling the top method when the stack contains the encoded value (i.e., 2*val - mini).
 The condition if(mini<el) return el; might not work correctly for all cases because el can be equal to mini but actually represents the encoded value.

Here is a revised version of your code with some improvements and additional comments to make the logic clearer:

cpp
*/


class MinStack {
public:
    stack <long long> st;
    long long mini;
    MinStack() {
        mini = LLONG_MAX;  
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val>mini) st.push(val);
            else{
				// Encode the value to handle the new minimum
                st.push(2LL*val-mini); //originally st.push(2*val-mini);
                mini=val;
            }
        }
        
    }
    
    void pop() {
        if(st.empty())  return;
        long long el=st.top();
        st.pop();
        if(el<mini){
            mini=2*mini-el;
        }
        
    }
    
    int top() {
        if(st.empty())  return -1;
        long long el=st.top();
        if(mini<el) return el;
        return mini;
    }
    
    int getMin() {
        if(st.empty())  return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
