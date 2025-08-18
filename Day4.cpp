// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
You are given two sorted arrays arr1 of size m and arr2 of size n. Your task is to merge these two arrays into a single sorted array without using any extra space (i.e., in-place merging). The elements in arr1 should be merged first, followed by the elements of arr2, resulting in both arrays being sorted after the merge.
*/

class Solution
{
public:
    void merge(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        int total = m + n;

        int gap = (total + 1) / 2;

        while (gap > 0)
        {
            int i = 0, j = gap;
            while (j < total)
            {
                int a, b;

                if (i < n)
                    a = arr1[i];
                else
                    a = arr2[i - n];

                if (j < n)
                    b = arr1[j];
                else
                    b = arr2[j - n];

                if (a > b)
                {
                    if (i < n && j < n)
                    {
                        swap(arr1[i], arr1[j]);
                    }
                    else if (i < n && j >= n)
                    {
                        swap(arr1[i], arr2[j - n]);
                    }
                    else
                    {
                        swap(arr2[i - n], arr2[j - n]);
                    }
                }
                i++, j++;
            }
            if (gap == 1)
                break;
            gap = (gap + 1) / 2;
        }
    }
};
// Input: arr1 = [2, 3, 8], arr2 = [4, 6, 10]
// Output: arr1 = [2, 3, 4], arr2 = [6, 8, 10]

int main()
{

    Solution s;

    vector<int> arr1 = {1, 1};
    vector<int> arr2 = {2};

    s.merge(arr1, arr2);

    cout << "arr1 = ";
    for (int x : arr1)
        cout << x << " ";
    cout << endl;

    cout << "arr2 = ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    std::cout << "Try programiz.pro";

    return 0;
}