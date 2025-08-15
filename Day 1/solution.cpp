#include <iostream>
#include <vector>

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
