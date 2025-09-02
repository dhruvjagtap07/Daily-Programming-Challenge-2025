#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given a postfix expression (also known as Reverse Polish Notation), your task is to evaluate the expression and
 return the result. The expression can contain integers and the four basic arithmetic operators +, -, *, and /.
 Assume that the input is always valid and the division operator performs integer division, truncating towards zero.
*/

class Solution
{
public:
    int evalPostfix(string expression)
    {
        stack<int> st;
        stringstream ss(expression);
        string token;

        while (ss >> token)
        {

            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result = 0;

                if (token == "+")
                    result = a + b;
                else if (token == "-")
                    result = a - b;
                else if (token == "*")
                    result = a * b;
                else if (token == "/")
                {

                    result = a / b;
                }

                st.push(result);
            }
            else
            {

                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

int main()
{
    Solution sol;
    cout << sol.evalPostfix("2 1 + 3 *") << endl;
    cout << sol.evalPostfix("5 6 +") << endl;
    cout << sol.evalPostfix("-5 6 -") << endl;
    cout << sol.evalPostfix("15 7 1 1 + - / 3 * 2 1 1 + + -") << endl;
    cout << sol.evalPostfix("5") << endl;
    return 0;
}
