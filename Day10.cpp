// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
Problem Statement:
You are given an array of strings strs[]. Your task is to group all the strings that are anagrams of each other. An anagram is a
word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
The goal is to return the grouped anagrams as a list of lists, where each sublist contains words that are anagrams of each other.

*/

using namespace std;

class Solution
{
public:
    vector<vector<string>> anagrams(vector<string> arr)
    {
        unordered_map<string, vector<string>> mp;
        vector<string> keys_order;

        for (string word : arr)
        {
            string key = word;
            sort(key.begin(), key.end());

            if (mp.find(key) == mp.end())
            {
                keys_order.push_back(key);
            }
            mp[key].push_back(word);
        }

        vector<vector<string>> result;
        for (string key : keys_order)
        {
            result.push_back(mp[key]);
        }
        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<vector<string>> result = s.anagrams({"abc", "bca", "cab", "xyz", "zyx", "yxz"});

    // For output uncomment the below lines

    // for (vector<string> s : result) {
    //     for (string word : s) {
    //         cout << word << ", ";
    //     }
    //     cout << endl;
    // }

    return 0;
}