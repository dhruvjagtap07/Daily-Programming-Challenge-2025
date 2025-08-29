#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
You are given a string S, and your task is to find the length of the longest substring that 
contains no repeating characters. A substring is a contiguous block of characters in the string.
*/
class Solution {
    public:
    int longestSubstring (string s) {
        unordered_set<char> seen;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while(seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLen = max(maxLen, right-left + 1);
        }
        return maxLen;
    }
};

int main () {
    Solution sol;
    cout << sol.longestSubstring("abcabcbb");
    return 0;
}
