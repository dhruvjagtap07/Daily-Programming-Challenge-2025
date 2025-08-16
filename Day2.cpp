// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

/*

Problem Statement:
You are given an array arr containing n-1 distinct integers. The array consists of integers taken from the
range 1 to n, meaning one integer is missing from this sequence. Your task is to find the missing integer.

*/

class Solution
{
public:
    int missingNo(vector<int> &arr)
    {
        int n = arr.size() + 1;
        int result = 0;

        for (int i = 1; i <= n; i++)
        {
            result ^= i;
            if (i <= n - 1)
                result ^= arr[i - 1];
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int result = s.missingNo(arr);

    cout << result << endl;

    return 0;
}