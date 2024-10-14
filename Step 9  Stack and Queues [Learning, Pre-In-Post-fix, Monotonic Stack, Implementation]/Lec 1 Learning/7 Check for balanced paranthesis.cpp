//tc: o(n)

#include<bits/stdc++.h>
bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    if(s.empty())   return true;

    for(int i=0;i<s.size();i++){

        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        } else {
            if (st.empty())
              return false;
            char ch = st.top();
            if (s[i] == ')' && ch == '(')
              st.pop();
            if (s[i] == ']' && ch == '[')
              st.pop();
            if (s[i] == '}' && ch == '{')
              st.pop();
        }
    }
    return st.empty();
}

int main(){
        
}