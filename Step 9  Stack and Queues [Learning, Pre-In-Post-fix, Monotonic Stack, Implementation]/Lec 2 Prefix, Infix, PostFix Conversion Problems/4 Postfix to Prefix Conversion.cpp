#include<bits/stdc++.h>
string postfixToPrefix(string &s){
    // Write your code here.
    stack<string> st;

	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
		{
			// convert the char into string
			st.push(string(1, s[i]));
		}
		else
		{
			
			string t1 = st.top();
			st.pop();
			string t2 = st.top();
			st.pop();

			st.push(s[i] + t2 + t1);
		}
	}
	
	return st.top();
}

int main(){
        
}