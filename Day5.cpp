// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
You are given an integer array arr of size n. An element is considered a leader if it is greater
 than all the elements to its right. Your task is to find all such leader elements in the array.
*/

class Solution
{
public:
    vector<int> arrayLeaders(vector<int> &arr)
    {
        int n = arr.size();
        int leader = arr[n - 1];
        int write = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > leader)
            {
                leader = arr[i];
                arr[--write] = arr[i];
            }
        }
        return vector<int>(arr.begin() + write, arr.end());
    }
};

int main()
{
    Solution s;
    vector<int> arr = {7, 10, 4, 10, 6, 5, 2};
    vector<int> result = s.arrayLeaders(arr);

    for (int num : result)
        cout << num << ' ';

    return 0;
}