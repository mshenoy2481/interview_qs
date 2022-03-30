#include <vector>
#include <iostream>

int MOD = 1000000007;

int nextNumWays(int numPeople, std::vector<int>& dp)
{
    if(numPeople == 0)
    {
        return 1;
    }
    if(dp[numPeople/2] != 0)
    {
        return dp[numPeople/2];
    }
    for(int i = 2;      i <= numPeople;     i += 2)
    {
        long l = nextNumWays(i-2, dp);
        long r = nextNumWays(numPeople-i, dp);
        dp[numPeople/2] = (dp[numPeople/2] + (l*r)%MOD)%MOD;
    }
    return dp[numPeople/2];
}

int numberOfWays(int numPeople) {
    std::vector<int> dp(numPeople/2+1, 0);
    dp[0] = 1;
    for(int i = 1;  i <= numPeople/2;     i++)
    {
        for(int j = 1;  j <= i;     j++)
        {
            long l = dp[j-1];
            long r = dp[i-j];
            long prod = (l*r)%MOD;
            dp[i] = (dp[i] + prod)%MOD;
        }
    }
    return dp.back();
}

int main()
{
    int numPeople = 4;
    std::cout << 4 << "   " << numberOfWays(4) << std::endl;
    std::cout << 6 << "   " << numberOfWays(6) << std::endl;
    std::cout << 22 << "   " << numberOfWays(22) << std::endl;
    std::cout << 1000 << "   " << numberOfWays(1000) << std::endl;
}
