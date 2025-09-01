#include <iostream>
using namespace std;
/*
Problem Statement:
Given a positive integer N, your task is to find the total number of divisors (factors) of N. 
A divisor of N is any integer that divides N without leaving a remainder.A divisor of a number 
is any integer that divides the number evenly (i.e., without a remainder). 
*/

class Solution {
    public:
    int countDivisors (int n) {
        int count = 0;
        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                if (n/i == i) count++;
                else count += 2;
            }
        }
        return count;
    }
};

int main () {
    Solution s;
    cout << s.countDivisors(997) << endl;
    return 0;
}
