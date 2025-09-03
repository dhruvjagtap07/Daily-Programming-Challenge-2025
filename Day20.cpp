// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>

/*
Problem Statement:
Given a stack of integers, your task is to write a function that sorts the stack in ascending order.
You are not allowed to use any additional data structure like arrays, lists, or another stack. The
only operations you are allowed to perform are push, pop, and peek on the stack. The sorting must
be performed using recursion only.
*/
using namespace std;

class Solution
{
private:
    void sortedInsert(stack<int> st, int element)
    {

        if (st.empty() || st.top() <= element)
        {
            st.push(element);
            return;
        }

        int temp = st.top();
        st.pop();
        sortedInsert(st, temp);
        st.push(temp);
    }

public:
    void sortStack(stack<int> st)
    {
        if (!st.empty())
        {
            int temp = st.top();
            st.pop();
            sortStack(st);
            sortedInsert(st, temp);
        }
    }
};

int main()
{
    Solution sol;
    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sol.sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}