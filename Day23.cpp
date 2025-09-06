#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem Statement:
You are given an array of integers arr and a positive integer k. Your task is to find the maximum
element in each sliding window of size k. The window slides from left to right, one element at a
time, and you need to return the maximum element for each of these windows.

*/

class Solution
{
public:
    vector<int> windowMaximum(vector<int> arr, int k)
    {
        int n = arr.size();
        vector<int> result;

        auto maxElement = 0;

        for (int i = 0; i <= n - k; i++)
        {
            auto maxElement = max_element(arr.begin() + i, arr.begin() + i + k);
            result.push_back(*maxElement);
        }

        return result;
    }
};
int main()
{
    Solution s;
    vector<int> result = s.windowMaximum({1, 3, -1, -3, 5, 3, 6, 7}, 3);

    cout << "Result: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}