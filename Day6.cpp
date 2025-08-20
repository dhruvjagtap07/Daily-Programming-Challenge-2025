#include <bits/stdc++.h>
using namespace std;

/*
Problem statement:
You are given an integer array arr of size n. Your task is to find all the subarrays whose elements sum up to zero. A subarray is defined as a contiguous part of the array, and you must return the starting and ending indices of each subarray.

*/

class Solution
{
public:
    vector<pair<int, int>> subArraySum0(vector<int> &arr)
    {
        unordered_map<long long, vector<int>> mp;
        vector<pair<int, int>> result;
        long long prefix = 0;
        mp[0].push_back(-1);
        for (int i = 0; i < arr.size(); i++)
        {
            prefix += arr[i];
            if (mp.find(prefix) != mp.end())
            {
                for (int start : mp[prefix])
                {
                    result.push_back({start + 1, i});
                }
            }
            mp[prefix].push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> ans = s.subArraySum0(arr);
    for (auto &p : ans)
        cout << "(" << p.first << ", " << p.second << ") ";
    return 0;
}
