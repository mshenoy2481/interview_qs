#include <iostream>
#include <vector>
#include <algorithm>

int getNextLongest(const std::string& text1, const std::string& text2, int ind1, int ind2, std::vector<std::vector<int>>& dp)
{
    if(ind1 == text1.length() || ind2 == text2.length())
    {
        return 0;
    }
    if(dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if(text1[ind1] == text2[ind2])
    {
        dp[ind1][ind2] = 1 + getNextLongest(text1, text2, ind1+1, ind2+1, dp);
    }
    else
    {
        dp[ind1][ind2] = std::max(getNextLongest(text1, text2, ind1+1, ind2, dp),
                                    getNextLongest(text1, text2, ind1, ind2+1, dp));
    }
    return dp[ind1][ind2];
}

int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<int> dp(text2.length()+1, 0);
    std::vector<int> nextDp(text2.length()+1, 0);
    for(int i = text1.length()-1;  i >= 0;      i--)
    {
        for(int j = text2.length()-1;   j >= 0;     j--)
        {
            if(text1[i] == text2[j])
            {
                dp[j] = 1 + nextDp[j+1];
            }
            else
            {
                dp[j] = std::max(dp[j+1], nextDp[j]);
            }
        }
        nextDp = dp;
    }
    return dp[0];
}

int main()
{
    std::cout << longestCommonSubsequence("abcde", "ace") << std::endl;
    std::cout << longestCommonSubsequence("abc", "abc") << std::endl;
    std::cout << longestCommonSubsequence("abc", "efg") << std::endl;
}
