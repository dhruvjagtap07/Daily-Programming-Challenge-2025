#include <iostream>

using namespace std;

/*

Problem Statement:
You are given a string s. Your task is to find and return the longest palindromic substring 
within the given string. A palindrome is a string that reads the same forwards and backwards.

*/
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, maxLen);
            expand(s, i, i+1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

private:
    void expand(string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};

int main () {
    Solution s;
    cout << s.longestPalindrome ("aaa") << endl;
    return 0;
}
