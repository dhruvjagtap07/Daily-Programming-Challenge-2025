#include <iostream>
#include <stack>
using namespace std;

/*
Problem Statement:
You are given a stack of integers, and your task is to write a function that reverses the stack using recursion.
You are not allowed to use any additional data structure (like arrays, lists, or another stack). The only
operations you are allowed to perform are push, pop, and peek on the stack. The reversal must be done using
recursion only.
*/

class Solution
{
private:
    void reverseInsert(stack<int> &st, int element)
    {
        if (st.empty())
        {
            st.push(element);
            return;
        }
        int top = st.top();
        st.pop();
        reverseInsert(st, element);
        st.push(top);
    }

public:
    void reverseStack(stack<int> &st)
    {
        if (!st.empty())
        {
            int temp = st.top();
            st.pop();
            reverseStack(st);
            reverseInsert(st, temp);
        }
    }
};

int main()
{
    Solution s;

    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack (top to bottom): ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    s.reverseStack(st);

    cout << "Reverse Stack (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}