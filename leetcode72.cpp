#include <vector>
#include <iostream>
#include <algorithm>

int tryNextDistance(const std::string& word1, const std::string& word2, int ind1, int ind2, std::vector<std::vector<int>>& dp)
{
    if(ind1 == word1.length())
    {
        return (word2.length()-ind2);
    }
    else if(ind2 == word2.length())
    {
        return (word1.length()-ind1);
    }
    if(dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if(word1[ind1] == word2[ind2])
    {
        dp[ind1][ind2] = tryNextDistance(word1, word2, ind1+1, ind2+1, dp);
        return dp[ind1][ind2];
    }
    int minEdits = std::min(tryNextDistance(word1, word2, ind1+1, ind2+1, dp),
                            tryNextDistance(word1, word2, ind1+1, ind2, dp));
    minEdits = std::min(minEdits, tryNextDistance(word1, word2, ind1, ind2+1, dp));
    dp[ind1][ind2] = minEdits+1;
    return dp[ind1][ind2];
}


int minDistance(std::string word1, std::string word2) {
    std::vector<std::vector<int>> dp(word1.size()+1, std::vector<int>(word2.size()+1, -1));
    for(int i = 0; i <= word2.length();  i++)
    {
        dp[word1.length()][i] = word2.length()-i;
    }
    for(int i = 0;  i <= word1.length();     i++)
    {
        dp[i][word2.length()] = word1.length()-i;
    }
    for(int ind1 = word1.length()-1;   ind1 >= 0;      ind1--)
    {
        for(int ind2 = word2.length()-1;   ind2 >= 0;      ind2--)
        {
            if(word1[ind1] == word2[ind2])
            {
                dp[ind1][ind2] = dp[ind1+1][ind2+1];
            }
            else
            {
                dp[ind1][ind2] = std::min(dp[ind1+1][ind2+1], dp[ind1+1][ind2]);
                dp[ind1][ind2] = std::min(dp[ind1][ind2], dp[ind1][ind2+1]);
                dp[ind1][ind2]++;
            }
        }
    }
    return dp[0][0];
    //return tryNextDistance(word1, word2, 0, 0, dp);
}

int main()
{
    std::cout << minDistance("horse", "ros") << std::endl;
    std::cout << minDistance("intention", "execution") << std::endl;
}
