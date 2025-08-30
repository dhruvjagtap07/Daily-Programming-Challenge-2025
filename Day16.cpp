#include <iostream>
using namespace std;

/*
Problem Statement:
You are given two integers, N and M. Your task is to find the Least Common Multiple (LCM) of these
two numbers. The LCM of two integers is the smallest positive integer that is divisible by both N and M.
*/
class Solution
{
private:
    long long gcd(long long a, long long b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    long long lcm(long long a, long long b)
    {
        long long gc = gcd(a, b);
        return (a / gc) * b;
    }
};
int main()
{
    Solution s;
    cout << s.lcm(123456, 789012);

    return 0;
}