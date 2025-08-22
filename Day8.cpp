// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Statement:
You are given a string s that consists of multiple words separated by spaces. Your task is to reverse the
order of the words in the string. Words are defined as sequences of non-space characters. The output string
should not contain leading or trailing spaces, and multiple spaces between words should be reduced to a
single space.
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        string word;

        for (char c : s)
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
            }
        }
        if (!word.empty())
            words.push_back(word);

        reverse(words.begin(), words.end());

        string result = "";

        for (int i = 0; i < (int)words.size(); i++)
        {
            if (i)
                result += ' ';
            result += words[i];
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    cout << "[" << sol.reverseWords("  hello   world  ") << "]\n";
    cout << "[" << sol.reverseWords("the sky is blue") << "]\n";
    cout << "[" << sol.reverseWords("a good   example") << "]\n";
    cout << "[" << sol.reverseWords("    ") << "]\n";

    return 0;
}