#include <iostream>
#include <vector>

/*
Problem Statement:
You are given an array arr consisting only of 0s, 1s, and 2s. The task is to sort the array in increasing order
in linear time (i.e., O(n)) without using any extra space. This means you need to rearrange the array in-place.
*/

using namespace std;

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int left = 0, mid = 0;
        int right = arr.size() - 1;

        while (mid <= right)
        {
            if (arr[mid] == 0)
            {
                swap(arr[left++], arr[mid++]);
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[right--]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = {};

    s.sort012(arr);

    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
