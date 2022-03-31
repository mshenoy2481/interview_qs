#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

int findLCS(const std::string& s, const std::string& t, int sInd, int tInd, std::vector<std::vector<int>>& dp)
{
    if(sInd == s.length() || tInd == t.length())
    {
        return 0;
    }
    if(dp[sInd][tInd] != -1)
    {
        return dp[sInd][tInd];
    }
    if(s[sInd] == t[tInd])
    {
        dp[sInd][tInd] = 1 + findLCS(s, t, sInd+1, tInd+1, dp);
    }
    else
    {
        dp[sInd][tInd] = std::max(findLCS(s,t,sInd+1,tInd, dp), findLCS(s,t,sInd,tInd+1, dp));
    }
    return dp[sInd][tInd];
}

int longestPalindromeSubseq(std::string s) {
    std::string t(s.rbegin(), s.rend());
    std::vector<int> dp(s.length()+1);
    std::vector<int> nextDp(s.length()+1);
    for(int i = s.length()-1;   i >= 0;     i--)
    {
        for(int j = t.length()-1;   j >= 0; j--)
        {
            if(s[i] == t[j])
            {
                dp[j] = 1+nextDp[j+1];
            }
            else
            {
                dp[j] = std::max(nextDp[j], dp[j+1]);
            }
        }
        nextDp = dp;
    }
    return dp[0];
//      return findLCS(s, t, 0, 0, dp);
}


int main()
{
    std::cout << longestPalindromeSubseq("bbbab") << std::endl;
    std::cout << longestPalindromeSubseq("cbbd") << std::endl;
}
