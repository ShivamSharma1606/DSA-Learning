string postToInfix(string s)
{

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
			if (st.size() < 2) //optinal for better coding
			{
				throw runtime_error("Invalid postfix expression");
			}
			string t1 = st.top();
			st.pop();
			string t2 = st.top();
			st.pop();

			st.push('(' + t2 + s[i] + t1 + ')');
		}
	}
	if (st.size() != 1)
	{
		throw runtime_error("Invalid postfix expression");
	}
	return st.top();
}