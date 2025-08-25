// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem statement:
You are given a string s. Your task is to generate and return all possible permutations of the characters in
the string. A permutation is a rearrangement of the characters in the string, and each character must appear
exactly once in every permutation. If there are duplicate characters in the string, the resulting permutations
should also be unique (i.e., no repeated permutations).
*/

class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> result;
        sort(s.begin(), s.end());
        vector<bool> used(s.size(), false);
        string current;
        backtrack(s, used, current, result);
        return result;
    }

private:
    void backtrack(string &s, vector<bool> &used, string &current, vector<string> &result)
    {
        if (current.size() == s.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {

            if (used[i])
                continue;

            if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            current.push_back(s[i]);

            backtrack(s, used, current, result);

            current.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    vector<string> res1 = sol.permutation("abc");

    cout << "Input: abc\nOutput: ";
    for (auto &p : res1)
        cout << p << " ";

    return 0;
}