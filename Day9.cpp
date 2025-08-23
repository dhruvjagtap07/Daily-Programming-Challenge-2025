// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

/* Problem Statement:
You are given an array of strings strs[], consisting of lowercase letters. Your task is to find the longest
common prefix shared among all the strings. If there is no common prefix, return an empty string "".A common
prefix is a substring that appears at the beginning of all the strings in the array. The task is to identify
the longest such prefix that all strings share.
*/
using namespace std;

class Solution
{
public:
    string longestPrefix(vector<string> str)
    {
        if (str.empty())
            return "";
        string first = str[0];
        string result = "";

        for (int i = 0; i < first.size(); i++)
        {
            char c = first[i];
            for (int j = 0; j < str.size(); j++)
            {
                if (i >= str[j].size() || str[j][i] != c)
                {
                    return result;
                }
            }

            result += c;
        }

        return result;
    }
};

int main()
{
    Solution s;

    cout << s.longestPrefix({"apple", "ape", "april"});

    return 0;
}