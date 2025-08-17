// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
You are given an array arr containing n+1 integers, where each integer is in the range [1, n] inclusive.
There is exactly one duplicate number in the array, but it may appear more than once. Your task is to
find the duplicate number without modifying the array and using constant extra space.
*/

class Solution
{
public:
    int duplicate(vector<int> &arr)
    {
        int tortoise = arr[0];
        int hare = arr[0];

        while (true)
        {
            tortoise = arr[tortoise];
            hare = arr[arr[hare]];
            if (tortoise == hare)
                break;
        }

        tortoise = arr[0];
        while (tortoise != hare)
        {
            tortoise = arr[tortoise];
            hare = arr[hare];
        }

        return hare;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1};
    cout << s.duplicate(arr);

    return 0;
}