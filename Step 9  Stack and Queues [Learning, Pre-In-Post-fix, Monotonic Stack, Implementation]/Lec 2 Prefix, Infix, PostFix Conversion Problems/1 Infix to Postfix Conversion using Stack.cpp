// working on samNotes:
// tc: o(n) + O(n)
// sc: o(n) + O(n)

#include <bits/stdc++.h>
int priority(char check)
{

	if (check == '^')
		return 3;
	else if (check == '*' || check == '/')
		return 2;
	else if (check == '+' || check == '-')
		return 1;
	return -1;
}

string infixToPostfix(string s)
{
	// Write your code here
	string ans;
	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
		{
			ans.push_back(s[i]);
		}
		else if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && priority(s[i]) <= priority(st.top()))
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}