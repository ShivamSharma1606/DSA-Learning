//same as postfix to infix conversion
//we have to iterate from last to first
//'(' + t1 + s[i] + t2 + ')' is used not '(' + t2 + s[i] + t1 + ')' of postF to InF

#include<bits/stdc++.h>
string prefixToInfixConversion(string &s){
	// Write your code here.
	stack<string> st;

	for (int i = s.size()-1; i >= 0; i--)
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

			st.push('(' + t1 + s[i] + t2 + ')');
		}
	}
	
	return st.top();
	
	
}

int main(){
    
}