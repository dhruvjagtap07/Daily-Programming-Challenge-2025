
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Problem Statement:
You are given an array of integers and an integer k. Your task is to find the first element
in the array that appears exactly k times. If no such element exists, return -1.
*/

class Solution
{
public:
    int kTimesElement(vector<int> arr, int k)
    {

        unordered_map<int, int> freq;

        for (int num : arr)
            freq[num]++;

        for (int num : arr)
            if (freq[num] == k)
                return num;

        return -1;
    }
};

int main()
{

    Solution s;

    cout << s.kTimesElement({1, 3, 2, 3, 2}, 2);

    return 0;
}