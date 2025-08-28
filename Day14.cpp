#include <iostream>
#include <unordered_map>
using namespace std;

/*
Problem Statement:
You are given a string s of lowercase English alphabets and an integer k. Your task
is to count all possible substrings of s that contain exactly k distinct characters.
*/
class Solution {
    private:
    int atMostKDistinct (const string &s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            result += right - left + 1;
         }

         return result;
     }

     public:
     int countKDistinctSubstrings(const string& s, int k ) {
         return atMostKDistinct(s, k) - atMostKDistinct(s, k-1);
     }
};

int main () {
    Solution sol;
    string s;
    int k;
    cin >> s >> k;
    cout << sol.countKDistinctSubstrings(s, k) << endl;
    return 0;
}

