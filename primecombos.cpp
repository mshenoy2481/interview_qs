/**
 * Given a string representing a positive valid number, print the number of ways in which the string can be split such that every split is a prime number.
 *
 * E.g. 3257
 * 3257 can be split as [3,2,5,7], [3,257], [3257]. So result should be 3.
 *
 * 1111
 * 1111 can be split as [11,11]. So result should be 1.
 *
 * 1000
 * 1000 cannot be split into any primes. So result should be 0.
 *
 * 1
 * 1 cannot be split any further and is not a prime. So result should be 0.
 *
 * 3
 * 3  cannot be split any further and is a prime. So result should be 1.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

bool isPrime(int num)
{
    int sqrtNum = std::sqrt(num);
    if(num <= 1)
    {
        return false;
    }
    for(int i = 2;  i <= sqrtNum;    i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}

int countNext(int ind, const std::vector<std::vector<bool>>& dp, std::vector<int>& dpCount)
{
    if(ind == dp.size())
    {
        return 1;
    }
    int totalCount = 0;
    if(dpCount[ind] != -1)
    {
        return dpCount[ind];
    }
    for(int i = ind;    i < dp.size();  i++)
    {
        if(dp[ind][i])
        {
            totalCount += countNext(i+1, dp, dpCount);
        }
    }
    dpCount[ind] = totalCount;
    return totalCount;
}

int countCombinations(const std::string& str)
{
    std::vector<std::vector<bool>> dp(str.length(), std::vector<bool>(str.length(), false));
    std::vector<int> dpCount(str.length(), -1);
    for(int i = 0;  i < str.length();   i++)
    {
        for(int j = i;  j < str.length();   j++)
        {
            dp[i][j] = isPrime(std::stoi(str.substr(i,j-i+1)));
        }
    }
    return countNext(0, dp, dpCount);
}

int main(int argv, const char** argc)
{
    std::ifstream testFileStrm("./primecombos_test");
    std::string nextStr = "";
    //while(std::getline(testFileStrm, nextStr))
    while(testFileStrm >> nextStr)
    {
        std::cout << "The number of combinations for " << nextStr << " : "
                  << countCombinations(nextStr) << std::endl;
    }
}
