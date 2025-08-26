// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

/*
Problem Statement:
You are given a string s consisting of different types of parentheses: (), {}, and []. Your task is
to determine whether the given string is valid. A string is considered valid if:
1. Every opening bracket has a corresponding closing bracket of the same type.
2. The brackets are closed in the correct order. This means that a closing
   bracket must close the most recent unmatched opening bracket.

*/

class Solution
{
public:
    bool validParantheses(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;

                if (s[i] == ')' && st.top() != '(')
                    return false;
                if (s[i] == '}' && st.top() != '{')
                    return false;
                if (s[i] == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

int main()
{
    // Write C++ code here
    Solution sol;

    cout << sol.validParantheses("([)]");

    return 0;
}