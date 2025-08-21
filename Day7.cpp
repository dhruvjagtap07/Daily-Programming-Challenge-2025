// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

/*
Problem Statement:
You are given an array height[] of non-negative integers where each element represents the height of a bar in a histogram-like structure. These bars are placed next to each other, and the width of each bar is 1 unit. When it rains, water gets trapped between the bars if there are taller bars on both the left and right of the shorter bars. The task is to calculate how much water can be trapped between these bars after the rain.

*/

using namespace std;

class Solution
{
public:
    int maxWater(vector<int> arr)
    {
        int n = arr.size();
        if (n < 3)
            return 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;

        int water = 0;

        while (left < right)
        {
            if (arr[left] < arr[right])
            {
                if (arr[left] >= leftMax)
                {
                    leftMax = arr[left];
                }
                else
                {
                    water += leftMax - arr[left];
                }
                left++;
            }
            else
            {
                if (arr[right] >= rightMax)
                {
                    rightMax = arr[right];
                }
                else
                {
                    water += rightMax - arr[right];
                }
                right--;
            }
        }
        return water;
    }
};

int main()
{
    Solution s;
    cout << s.maxWater({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << endl;

    return 0;
}