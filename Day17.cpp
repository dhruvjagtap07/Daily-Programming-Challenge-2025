#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statment:
Given a positive integer N, your task is to find its prime factorization. Return a list of prime
numbers that multiply together to give N. If N is prime, the output should be a list containing only N.
*/

class Solution
{
public:
    vector<int> primeFactors(int n)
    {
        vector<int> factors;

        while (n % 2 == 0)
        {
            factors.push_back(2);
            n /= 2;
        }

        for (int i = 3; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                factors.push_back(i);
                n /= i;
            }
        }

        if (n > 2)
            factors.push_back(n);

        return factors;
    }
};

int main()
{
    Solution sol;

    vector<int> result = sol.primeFactors(18);

    for (int num : result)
        cout << num << ' ';

    return 0;
}