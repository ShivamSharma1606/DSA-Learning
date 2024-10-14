// https://leetcode.com/discuss/interview-question/5281339/Stack-Every-Possible-Conversion-(INFIXPREFIXPOSTFIX)-with-explanation/
// a good article for user checking perspective

string preToPost(string s)
{
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; i--)
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

            st.push(t1 + t2 + s[i]);
        }
    }

    return st.top();
}
