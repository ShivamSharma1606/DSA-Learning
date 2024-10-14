#include <bits/stdc++.h>
using namespace std;

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

string infixToPrefixConversion(string &s)
{
    // Step 1: Reverse the infix expression
    reverse(s.begin(), s.end());

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    // Step 3: Convert the modified infix expression to postfix
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
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string infix = "((A-(B/C))*((A/K)-L))";
    cout << "Prefix : " << infixToPrefixConversion(infix) << endl;
    return 0;
}

/*
important point to discuss //chatGPT

Handling Exponentiation Operator ^:

cpp
Copy code
if (s[i] == '^') {
    while (!st.empty() && priority(s[i]) <= priority(st.top())) {
        ans.push_back(st.top());
        st.pop();
    }
}
Exponentiation Special Case: The exponentiation operator ^ is right-associative. This means an operator with the same precedence should stay on the stack to be processed after the current ^ operator.
Condition: While the stack is not empty and the precedence of the current ^ operator is less than or equal to the precedence of the operator at the top of the stack, pop operators from the stack to the ans string.
Action: Push the operator at the top of the stack to the ans string and pop it from the stack.
Handling Other Operators (+, -, *, /):

cpp
Copy code
else {
    while (!st.empty() && priority(s[i]) < priority(st.top())) {
        ans.push_back(st.top());
        st.pop();
    }
}
General Case: For all other operators, the standard precedence rules apply. These operators are left-associative, meaning an operator with the same precedence or higher should be popped from the stack before pushing the current operator.
Condition: While the stack is not empty and the precedence of the current operator is less than the precedence of the operator at the top of the stack, pop operators from the stack to the ans string.
Action: Push the operator at the top of the stack to the ans string and pop it from the stack.


*/